#include "studregpage.h"
#include "ui_studregpage.h"
#include <QTimer>

StudRegPage::StudRegPage(QWidget *parent, Data * data) :
    QDialog(parent),
    ui(new Ui::StudRegPage)
{
    ui->setupUi(this);
    this->data = data;
    ui->lineEdit->setReadOnly(true);
}

StudRegPage::~StudRegPage()
{
    delete ui;
}
