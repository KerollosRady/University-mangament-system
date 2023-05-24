#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>
#include <viewstudent.h>
#include <viewcoursesofstudent.h>
#include <coursevisualize.h>
#include <registertime.h>
AdminPage::AdminPage(QWidget *parent,QMainWindow * loginpage, Data* data) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    this->data =  data ;
    this->loginpage = loginpage ;
    ui->save->hide() ;
    ui->auto_generate->hide() ;
    ui->updateSem->hide();
    home() ;

}

AdminPage::~AdminPage()
{
    cout<<"delete ui; delete ptrCourse ; delete welcome;" ;
    delete ui;
    delete welcome;
}
void AdminPage::paint_current(QPushButton * b , int i){
    QString currentStyleSheet = b->styleSheet();
    // Modify the background color property in the stylesheet
    if(i==1)
    currentStyleSheet.replace("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);",
                              "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(255, 255, 255), stop:1 rgb(53, 53, 53));");
    else
     currentStyleSheet.replace("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(255, 255, 255), stop:1 rgb(53, 53, 53));" ,
                                  "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);"
                                  );
    b->setStyleSheet(currentStyleSheet) ;
}
void AdminPage::paint_button(){
    for(auto item : this->children())
     if(QPushButton* button = qobject_cast<QPushButton*>(item))
         paint_current(button,0) ;
}
void AdminPage::on_logout_clicked()
{
    this->hide()  ;
    loginpage->show() ;
}

void AdminPage::on_NewCourse_clicked()
{
    paint_button() ;
    paint_current(ui->NewCourse,1) ;
    ptrCourse = new newCourse(nullptr,data);
    ui->scrollArea->setWidget(ptrCourse) , ptrCourse->show();
}

void AdminPage::on_HomeButton_clicked()
{
    home() ;
}
void AdminPage::home(){
    paint_button() ;
    paint_current(ui->HomeButton,1) ;
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
}
void AdminPage::on_EditCourse_clicked()
{
    paint_button() ;
    paint_current(ui->EditCourse,1) ;
    ptrEdit = new EditCourse(nullptr,data);
    ui->scrollArea->setWidget(ptrEdit), ptrEdit->show();
}

void AdminPage::on_NewStudent_clicked()
{
    paint_button() ;
    paint_current(ui->NewStudent,1) ;
    newStd = new newStudent(nullptr, data);
    ui->scrollArea->setWidget(newStd);
    newStd->show();
}

void AdminPage::on_ViewStudent_clicked()
{
    paint_button() ;
    paint_current(ui->ViewStudent,1) ;
    ui->scrollArea->setWidget(new viewStudent(nullptr , &data->course , &data->student)) ;
}


void AdminPage::on_ViewCourse_clicked()
{
    paint_button() ;
    paint_current(ui->ViewCourse,1) ;
    ui->scrollArea->setWidget(new ViewCoursesOfStudent(nullptr ,data)) ;
}


void AdminPage::on_CourseVisual_clicked()
{
    paint_button() ;
    paint_current(ui->CourseVisual,1) ;
    ui->scrollArea->setWidget(new CourseVisualize(nullptr , data , ui->save , ui->auto_generate));
    ui->save->show() ;
    ui->auto_generate->show() ;
}


void AdminPage::on_RegTim_clicked()
{
    paint_button() ;
    paint_current(ui->RegTim,1) ;
    ui->scrollArea->setWidget(new RegisterTime(nullptr , data, ui->updateSem));
    ui->updateSem->show() ;
}

