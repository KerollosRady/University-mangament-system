#pragma once
#include "registerform.h"
#include "ui_registerform.h"
#include <QCheckBox>
#include <QFont>
#include <qtimer.h>
RegisterForm::RegisterForm(QWidget *parent,vector<Course> * courses, Student * stud  ) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    this->courses = courses ;
    this->stud = stud ;
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
    ui->check_add->hide() ;
    ui->courseList->show();
   // ui->checkBox->setEnabled(false); // disable the checkbox
    ui->checkBox->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->checkBox->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_1->setReadOnly(true) ;
    ui->lineEdit_2->setReadOnly(true) ;
    ui->lineEdit_4->setReadOnly(true) ;
    ui->lineEdit_5->setReadOnly(true) ;
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_courseList_currentIndexChanged(int index)
{
        index-- ;
        if(index==-1)
        {
        ui->listWidget->clear();
        ui->lineEdit_1->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("") ;
        ui->checkBox->setCheckState(Qt::Unchecked);
        return  ;
        }
        Course &c = courses->at(index);
        ui->lineEdit_1->setText(QString::fromStdString(c.name));
        ui->lineEdit_2->setText(QString::fromStdString(c.instructor));
        ui->lineEdit_4->setText(QString::fromStdString(to_string(c.MaxNumOfStud)));
        ui->lineEdit_5->setText(QString::fromStdString(to_string(c.hours)));
        ui->lineEdit_1->setAlignment(Qt::AlignCenter) ;
        ui->lineEdit_2->setAlignment(Qt::AlignCenter) ;
        ui->lineEdit_4->setAlignment(Qt::AlignCenter) ;
        ui->lineEdit_5->setAlignment(Qt::AlignCenter) ;
        ui->checkBox->setCheckState(c.isElective ? Qt::Checked : Qt::Unchecked);
        ui->listWidget->clear();
        for(auto cc : c.PreReqCourses)
        {
            QListWidgetItem *item1 = new QListWidgetItem(QString::fromStdString(courses->at(cc).name), ui->listWidget);
            item1->setTextAlignment(Qt::AlignHCenter) ;
            ui->listWidget->addItem(item1) ;
        }
}
void RegisterForm::invalidMessages(int i ){
    int coursecode = ui->courseList->currentIndex()-1;
    if(i==0)
        ui->check_add->setText("This Course had been registered before .");
    else if(i==1)
        ui->check_add->setText(QString::fromStdString("Minimum "+to_string(courses->at(coursecode).hours)+" hours to register this course  . "));
    else if(i==2)
        ui->check_add->setText("You should finish Prerequired courses first  .");
    else if(i==3)
        ui->check_add->setText("This course has been closed ");
    else if (i==4)
        ui->check_add->setText("You should selecd a course");
    ui->check_add->setStyleSheet("color : red ;background-color: transparent;font-size:20px;") ;
    ui->check_add->show() ;
    QTimer::singleShot(2000, this, [=]() {
        ui->check_add->hide();
    });
}

void RegisterForm::on_RegisterButton_clicked()
{
    int coursecode = ui->courseList->currentIndex() -1;
    if (coursecode == -1){
        return invalidMessages(4);
    }
    if(stud->finishedCourses[coursecode])
        return invalidMessages(0) ;
    Course *c = &courses->at(coursecode) ;
    for(auto i : c->PreReqCourses){
        if(!stud->finishedCourses[i])
            return invalidMessages(2) ;
    }
    set<int> progress(stud->progressCourses.begin(), stud->progressCourses.end());
    if(progress.find(coursecode)!=progress.end())
        return invalidMessages(0) ;
    for(auto i : c->PreReqCourses){
        if(progress.find(i)!=progress.end())
             return invalidMessages(0) ;
    }
    if(stud->maximumHoursAllowed<courses->at(coursecode).hours)
        return invalidMessages(1) ;
    if(c->MaxNumOfStud==c->CurStudents.size())
        return invalidMessages(3) ;
    c->CurStudents.emplace(stoi(stud->ID.substr(0,4))-2000,stoi(stud->ID.substr(4,4))) ;
    stud->RegisterCourse(coursecode) ;
    stud->maximumHoursAllowed-=courses->at(coursecode).hours ;
    ui->check_add->setText("course has been registerd successfully") ;
    ui->check_add->setStyleSheet("color : green ;     background-color: transparent;font-size:20px;") ;
    ui->check_add->show() ;
    QTimer::singleShot(2000, this, [=]() {
        ui->check_add->hide();
    });
}

