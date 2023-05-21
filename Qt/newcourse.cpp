#pragma once
#include "newcourse.h"
#include "ui_newcourse.h"
#include <iostream>
using namespace std;

newCourse::newCourse(QWidget *parent, Data* data) :
    QDialog(parent),
    ui(new Ui::newCourse)
{
    ui->setupUi(this);
    this->data = data ;
    ui->check_add->hide();
    clear();
}

newCourse::~newCourse()
{
    delete ui;
}
void newCourse::clear(){
    ui->listWidget->clear();
    for(auto c : data->course)
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

    ui->check_add->show();
    QTimer::singleShot(2000, this, [=]() {
        ui->check_add->hide();
    });
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
    for (int i = 0 ; i < data->course.size(); i++){
        if (_name == data->course[i].name){
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
    c.isElective = ui->checkBox->isChecked()==true;
    c.insert(_name, _instructor, _maxStd, hours, s);
    c.x = rand()%900 ;
    c.y = rand()%450 ;
    data->course.push_back(c);
    ui->check_add->show();

    ui->check_add->setText("Added successfully");
    ui->check_add->setStyleSheet("background-color: transparent;color : green;font-size:20px;");
    QTimer::singleShot(2000, this, [=]() {
        ui->check_add->hide();
    });
    clear();
}

void newCourse::on_clear_clicked()
{
    clear();
    ui->check_add->setText("");
}
