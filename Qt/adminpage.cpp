#include "adminpage.h"
#include "ui_adminpage.h"
#include <loginpage.h>
AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
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

