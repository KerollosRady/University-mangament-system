#include "newstudent.h"
#include "ui_newstudent.h"

newStudent::newStudent(QWidget *parent, Data* data) :
    QDialog(parent),
    ui(new Ui::newStudent)
{
    ui->setupUi(this);
    this->data = data;
    ui->studentID->setReadOnly(true);
    ui->tableWidget->horizontalHeader()->resizeSection(0, 180);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0 ; i < data->course.size(); i++){

        QString str = QString::fromStdString(to_string(i));
        int sz = str.size();
        for (int j = 0; j < 17 - sz ; j++){
            str.push_back(' ');
        }
        str.push_back("|          ");
        str += QString::fromStdString(data->course[i].name);

        ui->courseList->addItem(str);
    }
    ui->courseList->show();
    ui->tableWidget->horizontalHeader()->
        setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
    ui->tableWidget->verticalHeader()->
        setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
    ui->tableWidget->setStyleSheet("color : white ; ") ;
    clear();
}

newStudent::~newStudent()
{
    delete ui;
}

void newStudent::clear(){
    ui->studentID->setText("");
    ui->check_add->setText("");
    ui->grade->hide();
    ui->ok->hide();
    enteredGrades = vector<float> (data->course.size(), -1);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->lineEdit_1->setText("");
    ui->courseList->setCurrentIndex(0);
    ui->tableWidget->hide();
}

void newStudent::on_courseList_currentIndexChanged(int idx)
{
    ui->tableWidget->show();
    idx--;
    if (idx == -1){
        ui->grade->hide();
        ui->ok->hide();
        return;
    }
    ui->ok->show();
    ui->grade->show();
    QString str;
    if (enteredGrades[idx] == -1){
        str = "";
    }
    else {
        std::string s = std::to_string(enteredGrades[idx]);
        str = QString::fromStdString(s);
    }
    ui->grade->setText(str);
}

bool newStudent::isFloat(std::string s){
    bool dot = 0;
    for (auto &i : s){
        if (i == '.'){
            if (dot == 0) dot = 1;
            else return false;
            continue;
        }
        if (i >= '0' && i <= '9') continue;
        return false;
    }
    return true;
}

void newStudent::on_ok_clicked()
{
    int idx = ui->courseList->currentIndex();
    idx--;
    string v = "";

    QString val = ui->grade->text();
    bool valid = 1;
    if (val.size() == 0)
        enteredGrades[idx] = -1 , valid = 0;
    else {
        v = val.toStdString();
        if (!isFloat(v))
            enteredGrades[idx] = -1 , valid = 0;
    }
    if (valid){
        float x = stof(v);
        enteredGrades[idx] = x >= 50 && x <= 100 ? x : -1;
    }
    if (enteredGrades[idx] == -1){
        ui->check_add->setText("Finish course grade must be an integer >= 50 and <= 100");
        ui->check_add->setStyleSheet("background-color: transparent;color : red;font-size:20px;");
        ui->check_add->show();
        QTimer::singleShot(5000, this, [=]() {
            ui->check_add->hide();
        });
    }
    else
        ui->check_add->setText("");
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    for (int i = 0 ; i < enteredGrades.size(); i++){
        if (enteredGrades[i] == -1) continue;
        int sz = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(sz);
        QString name = QString::fromStdString(data->course[i].name);
        string gr = to_string(enteredGrades[i]);
        if (gr.size() > 5)gr = gr.substr(0,5);
        ui->tableWidget->setItem(sz,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(sz,1,new QTableWidgetItem(QString::fromStdString(gr)));
    }

}

void newStudent::on_Add_clicked()
{
    bool valid = 0;
    string _name = ui->lineEdit_1->text().toStdString();
    if (_name.size() < 15){
        ui->check_add->setText("Student name is too short");
        ui->check_add->setStyleSheet("background-color: transparent;color : red;font-size:20px;");
        ui->check_add->show();
        QTimer::singleShot(5000, this, [=]() {
            ui->check_add->hide();
        });
        return;
    }

    for (int i = 0 ; i < enteredGrades.size(); i++){
        if (enteredGrades[i] == -1) continue;
        for (auto &p : data->course[i].PreReqCourses){
            if (enteredGrades[p] == -1){
                QString pre = QString::fromStdString(data->course[p].name);
                QString crs = QString::fromStdString(data->course[i].name);

                ui->check_add->setText(pre + " is pre Required for " + crs);
                ui->check_add->setStyleSheet("background-color: transparent;color : red;font-size:20px;");
                ui->check_add->show();
                QTimer::singleShot(5000, this, [=]() {
                    ui->check_add->hide();
                });
                return;
            }
        }
    }

    ui->check_add->setText("Added successfully");
    ui->check_add->setStyleSheet("background-color: transparent;color : green;font-size:20px;");
    ui->check_add->show();
    QTimer::singleShot(5000, this, [=]() {
        ui->check_add->hide();
    });
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = ltm->tm_year - 100;
    int id = data->student[year].size();
    Student newStd(year+2000, id , _name,data->course.size() , "Faculty of computer and information science .");
    ui->studentID->setText(
        "Student ID:     " + QString::fromStdString(newStd.ID) + "            "+
         "Password :    " + QString::fromStdString(newStd.getPassword()));

    ui->studentID->setStyleSheet("background-color: transparent;color : white;font-size:20px;");

    int finishedCnt = 0;
    double GPA = 0;
    for (int i = 0 ; i < enteredGrades.size(); ++i){
        if (enteredGrades[i] != -1){
            finishedCnt++;
            newStd.finishedCourses[i] = 1;
            newStd.courseGPA[i] = 4.0 * enteredGrades[i] / 100;
            GPA += enteredGrades[i];
        }
    }

    newStd.SemesterUpdate();
    newStd.CGPA = 4.0 * GPA / 100;
    newStd.academicSemster = 1;
    newStd.academicYear = finishedCnt/10 + 1;

    data->student[year].push_back(newStd);
}

void newStudent::on_clear_clicked()
{
    clear();
}
