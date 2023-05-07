#include "invaliddata.h"
#include "ui_invaliddata.h"

invalidData::invalidData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::invalidData)
{
    ui->setupUi(this);
}

invalidData::~invalidData()
{
    delete ui;
}
