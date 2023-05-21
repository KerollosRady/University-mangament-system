#include "viewstudent.h"
#include "ui_viewstudent.h"

viewStudent::viewStudent(QWidget *parent, vector<Course>* courses , vector<vector<Student>>* st) :
    QDialog(parent),
    ui(new Ui::viewStudent)
{
    ui->setupUi(this);
    this->courses = courses;
    this->students = st;

    ui->treeWidget->setStyleSheet("color : white ; ") ;
    ui->treeWidget->header()->setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
    ui->treeWidget->setColumnWidth(0,200);
    ui->treeWidget->hide();
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

}

viewStudent::~viewStudent()
{
    delete ui;
}

void viewStudent::on_courseList_currentIndexChanged(int idx)
{
    idx--;
    if (idx == -1){
        ui->treeWidget->hide();
        return;
    }
    ui->treeWidget->show();
    ui->treeWidget->clear();
    for ( auto &[year , idx] : courses->at(idx).CurStudents){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::fromStdString(students->at(year).at(idx).ID));
        item->setText(1,QString::fromStdString(students->at(year).at(idx).name));
        ui->treeWidget->addTopLevelItem(item) ;
    }
}

