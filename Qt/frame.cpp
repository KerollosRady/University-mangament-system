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
    qCritical()<<"delete My profile " ;
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

void Frame::on_ChangePassBtn_clicked()
{
    string s = this->ui->newPass->text().toStdString();
    bool ok =stud->validate_password(s) ;
    if(ok){
        stud->setPassword(s) ;
        ui->validation->setText("Password has been changed successfully");
        ui->validation->setStyleSheet("background-color: transparent;color : green ;") ;
        this->ui->pass->setText(QString::fromStdString(stud->getPassword())) ;
    }
    else
    {
        ui->validation->setText("Secure password: 1 digit, 1 uppercase, 1 lowercase.\n Length: 8-16.");
        ui->validation->setStyleSheet("background-color: transparent;color : red ;") ;
    }
}

