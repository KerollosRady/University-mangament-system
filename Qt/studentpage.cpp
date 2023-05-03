#include "studentpage.h"
#include "ui_studentpage.h"

StudentPage::StudentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentPage)
{
    ui->setupUi(this);
}

StudentPage::~StudentPage()
{
    delete ui;
}
