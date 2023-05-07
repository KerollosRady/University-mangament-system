#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();

}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_logout_clicked()
{
    this->hide()  ;
    (new LoginPage)->show() ;
}


void AdminPage::on_NewCourse_clicked()
{

    ptrCourse = new newCourse(nullptr) ;
    ui->scrollArea->setWidget(ptrCourse) , ptrCourse->show();

}


void AdminPage::on_HomeButton_clicked()
{

    welcome = new adminwelcome(nullptr);
    ui->scrollArea->setWidget(welcome) , welcome->show();
}
