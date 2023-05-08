#include "debuging.h"
#include "ui_debuging.h"

debuging::debuging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::debuging)
{
    ui->setupUi(this);
}

debuging::~debuging()
{
    delete ui;
}
