#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>

AdminPage::AdminPage(QWidget *parent,QMainWindow * loginpage, vector<Course>*courses) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
    this->courses =  courses ;
    this->loginpage = loginpage ;
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
