#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>
#include <viewstudent.h>
AdminPage::AdminPage(QWidget *parent,QMainWindow * loginpage, Data* data) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
    this->data =  data ;
    this->loginpage = loginpage ;
}

AdminPage::~AdminPage()
{
    cout<<"delete ui; delete ptrCourse ; delete welcome;" ;
    delete ui;
    delete welcome;
}
void AdminPage::on_logout_clicked()
{
    this->hide()  ;
    loginpage->show() ;
}

void AdminPage::on_NewCourse_clicked()
{
    ptrCourse = new newCourse(nullptr,data);
    ui->scrollArea->setWidget(ptrCourse) , ptrCourse->show();
}

void AdminPage::on_HomeButton_clicked()
{
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
}
void AdminPage::home(){
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
}
void AdminPage::on_EditCourse_clicked()
{
    ptrEdit = new EditCourse(nullptr,data);
    ui->scrollArea->setWidget(ptrEdit), ptrEdit->show();
}

void AdminPage::on_NewStudent_clicked()
{
    newStd = new newStudent(nullptr, data);
    ui->scrollArea->setWidget(newStd);
    newStd->show();
}

void AdminPage::on_ViewStudent_clicked()
{
    ui->scrollArea->setWidget(new viewStudent(nullptr , &data->course , &data->student)) ;
}

