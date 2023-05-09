#pragma once
#include "newcourse.h"
#include "ui_newcourse.h"
#include <iostream>
using namespace std;

newCourse::newCourse(QWidget *parent, vector<Course>*courses) :
    QDialog(parent),
    ui(new Ui::newCourse)
{
    ui->setupUi(this);
    this->courses = courses ;
    clear();
}

newCourse::~newCourse()
{
    delete ui;
}
void newCourse::clear(){
    ui->listWidget->clear();
    for(auto c : *courses)
    {
        // Create checkable items and add them to the list widget
        QListWidgetItem *item1 = new QListWidgetItem(QString::fromStdString(c.name), ui->listWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
    }

    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->spinBox->setValue(1);
    ui->lineEdit_4->setText("");
    ui->checkBox->setCheckState(Qt::Unchecked);
}

bool newCourse::isInt(string s){

    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}
void newCourse::invalidInputData(int idx){
    if (idx == 0)
        ui->check_add->setText("You must fill all Fields");
    else if(idx == 1)
        ui->check_add->setText("Muximum Students must be a positive integer");
    else if(idx == 2)
        ui->check_add->setText("The course name already exist");

    ui->check_add->setStyleSheet("background-color: transparent;color : red;font-size:20px;");
}
void newCourse::on_Add_clicked(){

    QString name = ui->lineEdit_1->text();
    QString instructor = ui->lineEdit_2->text();
    int hours = ui->spinBox->value();
    QString maxStd = ui->lineEdit_4->text();


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
    for (int i = 0 ; i < courses->size(); i++){
        if (_name == courses->at(i).name){
            invalidInputData(2);
            return;
        }
    }

    Course c;
    set<int> s;
    QListWidget *pre = ui->listWidget ;
    for(int i=0 ;i< pre->count() ;i++)
    {
        if(pre->item(i)->checkState()== Qt::Checked)
        {
            s.insert(i) ;
        }
    }
    c.isElective = ui->checkBox->isChecked();
    c.insert(_name, _instructor, _maxStd, hours, s);
    courses->push_back(c);
    ui->check_add->setText("Added successfully");
    ui->check_add->setStyleSheet("background-color: transparent;color : green;font-size:20px;");
    clear();
}

void newCourse::on_clear_clicked()
{
    clear();
    ui->check_add->setText("");
}
