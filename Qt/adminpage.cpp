#include "adminpage.h"
#include "ui_adminpage.h"
AdminPage::AdminPage(QWidget *parent,QMainWindow * loginpage) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    this->loginpage = loginpage ;
}

AdminPage::~AdminPage()
{
    delete ui;
}
void AdminPage::on_logout_clicked()
{
    this->hide()  ;
    loginpage->show() ;
}

