#include "framewelcome.h"
#include "ui_framewelcome.h"

FrameWelcome::FrameWelcome(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameWelcome)
{
    ui->setupUi(this);
}

FrameWelcome::~FrameWelcome()
{
    qCritical()<<"delete Frame Welcome" ;
    delete ui;
}
