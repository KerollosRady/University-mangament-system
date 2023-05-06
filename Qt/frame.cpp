#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent, Student *stud ) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    this->stud = stud ;
    load_data() ;
}

Frame::~Frame()
{
    delete ui;
}

void Frame::load_data(){
    this->ui->username->setText(QString::fromStdString(stud->name)) ;
    this->ui->Email->setText(QString::fromStdString(stud->getEmail())) ;
    this->ui->pass->setText(QString::fromStdString(stud->getPassword())) ;
    this->ui->AllowedHours->setText(QString::fromStdString(to_string(stud->maximumHoursAllowed))) ;
    this->ui->id->setText(QString::fromStdString(stud->ID)) ;
    this->ui->pass->setText(QString::fromStdString(stud->getPassword())) ;
    this->ui->AcadimicYear->setText(QString::fromStdString(to_string(stud->academicYear))) ;

}
