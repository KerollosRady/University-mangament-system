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

    for(auto c : *courses)
    {
        // Create checkable items and add them to the list widget
        QListWidgetItem *item1 = new QListWidgetItem(QString::fromStdString(c.name), ui->listWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
    }
    connect(ui->listWidget, &QListWidget::itemChanged, [=](QListWidgetItem *item){
        if (item->checkState() == Qt::Checked)
        {
            qDebug() << item->text() << "is checked";
        }
        else
        {
            qDebug() << item->text() << "is unchecked";
        }
    });
}

newCourse::~newCourse()
{
    delete ui;
}

bool newCourse::isInt(string s){

    for (int i = 0 ; i < s.size() ; ++i)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}


void newCourse::on_Add_clicked(){
//    qCritical<<"fjsdklfjsd" ;

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
    string _instructor = instructor.toStdString();
    int  _maxStd= stoi(maxStd.toStdString());
    int  _hours= stoi(hours.toStdString());

    if (_hours <= 0 || _maxStd <= 0){
        (new invalidData)->show(); return;
    }
    Course c;
    set<int> s;
    QListWidget *pre = ui->listWidget ;
    qDebug() << (QString::fromStdString(to_string(pre->count()))) ;
    for(int i=0 ;i< pre->count() ;i++)
    {
        if(pre->item(i)->checkState()== Qt::Checked)
        {
            s.insert(i) ;
//            qDebug() << pre->item(i)->text() << "is checked";
        }
    }
    c.isElective = ui->checkBox->isChecked();
    c.insert(_name, _instructor, _maxStd, _hours, s);
    courses->push_back(c);
}
