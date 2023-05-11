#include "frame.h"
#include "ui_frame.h"
#include <qtimer.h>
Frame::Frame(QWidget *parent,  Student *stud) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    this->stud = stud;
    ui->setupUi(this);
    ui->validation->hide() ;
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
    this->ui->collegeName->setText(QString::fromStdString(stud->collegeName)) ;
    this->ui->AllowedHours->setText(QString::fromStdString(to_string(stud->maximumHoursAllowed))) ;
    this->ui->id->setText(QString::fromStdString(stud->ID)) ;
   // this->ui->collegeName->setText(QString::fromStdString(stud->getPassword())) ;
    this->ui->AcadimicYear->setText(QString::fromStdString(to_string(stud->academicYear))) ;

}

void Frame::on_ChangePassBtn_clicked()
{
    string s = this->ui->newPass->text().toStdString();
    bool ok =stud->validate_password(s) ;
    if(ok && this->ui->newPass->text() == this->ui->confirmpass->text()){
        stud->setPassword(s) ;
        ui->validation->setText("Password has been changed successfully");
        ui->validation->setStyleSheet("background-color: transparent;color : green ;") ;
    }
    else
    {
        if(!ok)
        ui->validation->setText("Secure password: 1 digit, 1 uppercase, 1 lowercase.\n Length: 8-16.");
        else
        ui->validation->setText("Password and confirm password does not match");

        ui->validation->setStyleSheet("background-color: transparent;color : red ;") ;
    }
    ui->validation->show() ;
    QTimer::singleShot(5000, this, [=]() {
        ui->validation->hide();
    });
}

