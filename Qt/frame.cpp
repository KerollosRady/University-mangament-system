#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent, Student *stud ) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    this->stud = stud ;
    load_data() ;
    this->show() ;
}

Frame::~Frame()
{
    delete ui;
}

void Frame::load_data(){
    this->ui->username->setText(QString::fromStdString(stud->name)) ;
    this->ui->Email->setText(QString::fromStdString(stud->getEmail())) ;
}
