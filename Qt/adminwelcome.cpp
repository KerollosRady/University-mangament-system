#include "adminwelcome.h"
#include "ui_adminwelcome.h"

adminwelcome::adminwelcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwelcome)
{
    ui->setupUi(this);
}

adminwelcome::~adminwelcome()
{
    delete ui;
}
