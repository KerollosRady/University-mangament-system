#include "editCourse.h"
#include "ui_editcourse.h"
using namespace std;
EditCourse::EditCourse(QWidget *parent, vector<Course>*courses) :
    QDialog(parent),
    ui(new Ui::EditCourse)
{
    ui->setupUi(this);
    this->courses = courses;

    for (int i = 0 ; i < courses->size(); i++){

        QString str = QString::fromStdString(to_string(i));
        int sz = str.size();
        for (int j = 0; j < 17 - sz ; j++){
            str.push_back(' ');
        }
        str.push_back("|          ");
        str += QString::fromStdString(courses->at(i).name);

        ui->courseList->addItem(str);
    }
    ui->courseList->show();
    clear();
}

EditCourse::~EditCourse()
{
    delete ui;
}

void EditCourse::clear(){
    ui->listWidget->clear();
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->spinBox->setValue(1);
    ui->lineEdit_4->setText("");

    for(auto cc : *courses)
    {
        // Create checkable items and add them to the list widget
        QListWidgetItem *item1 = new QListWidgetItem(QString::fromStdString(cc.name), ui->listWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
    }
}
void EditCourse::on_courseList_currentIndexChanged(int index)
{
    clear();
    index--;

    if (index != -1){
        Course &c = courses->at(index);
        ui->lineEdit_1->setText(QString::fromStdString(c.name));
        ui->lineEdit_2->setText(QString::fromStdString(c.instructor));
        ui->spinBox->setValue(c.hours);
        ui->lineEdit_4->setText(QString::fromStdString(to_string(c.MaxNumOfStud)));
        ui->checkBox->setCheckState(c.isElective ? Qt::Checked : Qt::Unchecked);
        for (auto p : c.PreReqCourses){
            ui->listWidget->item(p)->setCheckState(Qt::Checked);
        }
    }
}

void EditCourse::on_clear_clicked()
{
    clear();
    ui->courseList->setCurrentIndex(0);
    ui->check_add->setText("");
}

void EditCourse::invalidInputData(int idx){
    if (idx == 0)
        ui->check_add->setText("You must fill all Fields");
    else if(idx == 1)
        ui->check_add->setText("Muximum Students must be a positive integer");
    else if(idx == 2)
        ui->check_add->setText("The course name already exist");
    else if (idx == 3)
        ui->check_add->setText("Nothing has changed");
    else if (idx == 4)
        ui->check_add->setText("select a course you need edit");
    else if (idx == 5)
        ui->check_add->setText("Course can't be pre Required for itself");

        ui->check_add->setStyleSheet("background-color: transparent;color : red;font-size:20px;");
}
bool EditCourse::isInt(string s){

    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}
void EditCourse::on_Edit_clicked()
{
    QString name = ui->lineEdit_1->text();
    QString instructor = ui->lineEdit_2->text();
    int hours = ui->spinBox->value();
    QString maxStd = ui->lineEdit_4->text();
    int idx = ui->courseList->currentIndex();
    idx--;
    if (idx == -1){
        invalidInputData(4);
        return;
    }
    if (name.size() == 0 || instructor.size() == 0 || maxStd.size() == 0){
        invalidInputData(0);
        return;
    }

    if (!isInt(maxStd.toStdString())){
        invalidInputData(1);
        return;
    }

    string _name = name.toStdString();
    string _instructor = instructor.toStdString();

    int  _maxStd= stoi(maxStd.toStdString());

    if (_maxStd <= 0){
        invalidInputData(1);
        return;
    }
    Course &selected = courses->at(idx);
    set<int> s;

    QListWidget *pre = ui->listWidget ;
    if (pre->item(idx)->checkState()== Qt::Checked){
        invalidInputData(5);
        pre->item(idx)->setCheckState(Qt::Unchecked);
        return;
    }
    for(int i=0 ;i< pre->count() ;i++)
    {
        if(pre->item(i)->checkState()== Qt::Checked)
        {
            s.insert(i) ;
        }
    }
    bool isElective = ui->checkBox->isChecked();
    if (_name == selected.name && _instructor == selected.instructor && isElective == selected.isElective
        && _maxStd == selected.MaxNumOfStud && hours == selected.hours && s == selected.PreReqCourses ){

        invalidInputData(3);
        return;
    }
    for (int i = 0 ; i < courses->size(); ++i){
        if (i == idx) continue;
        if (_name == courses->at(i).name){
            invalidInputData(2);
            return;
        }
    }
    selected.PreReqCourses.clear();
    selected.insert(_name,_instructor,_maxStd,hours,s);
    selected.isElective = isElective;
    ui->check_add->setText("Modified successfully");
    ui->check_add->setStyleSheet("background-color: transparent;color : green;font-size:20px;");
    clear();
    ui->courseList->setCurrentIndex(0);
}
