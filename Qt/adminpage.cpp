#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>

AdminPage::AdminPage(QWidget *parent,QMainWindow * loginpage, vector<Course>*courses, vector<vector<Student>>*st) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
    this->courses =  courses ;
    this->loginpage = loginpage ;
    this->students = st;
}

AdminPage::~AdminPage()
{
    cout<<"delete ui; delete ptrCourse ; delete welcome;" ;
    delete ui;
    delete ptrCourse ;
    delete welcome;
}
void AdminPage::on_logout_clicked()
{
    this->hide()  ;
    loginpage->show() ;
}

void AdminPage::on_NewCourse_clicked()
{
    ptrCourse = new newCourse(nullptr,courses);
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
    ptrEdit = new EditCourse(nullptr,courses);
    ui->scrollArea->setWidget(ptrEdit), ptrEdit->show();
}

void AdminPage::on_NewStudent_clicked()
{
    newStd = new newStudent(nullptr, courses, students);
    ui->scrollArea->setWidget(newStd);
    newStd->show();
}
