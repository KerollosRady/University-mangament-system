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
}

newCourse::~newCourse()
{
    delete ui;
    delete courses ;
}

bool newCourse::isInt(string s){

    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}


void newCourse::on_Add_clicked(){
    QString name = ui->lineEdit_1->text();
    QString instructor = ui->lineEdit_2->text();
    QString hours = ui->lineEdit_3->text();
    QString maxStd = ui->lineEdit_4->text();

    if (name.size() == 0 || instructor.size() == 0 || hours.size() == 0 || maxStd.size() == 0){
        (new invalidData)->show(); return;
    }

    if (!isInt(hours.toStdString()) || !isInt(maxStd.toStdString())){
        (new invalidData)->show(); return;
    }
    string _name = name.toStdString();
    string _instructor = name.toStdString();
    int _hours = stoi(maxStd.toStdString());
    int _maxStd = stoi(hours.toStdString());

    if (_hours <= 0 || _maxStd <= 0){
        (new invalidData)->show(); return;
    }
    Course c;
    c.isElective = ui->checkBox->isChecked();
    c.insert(_name, _instructor, _maxStd, _hours, {});
    courses->push_back(c);
}

