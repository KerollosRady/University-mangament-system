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

void StudentPage::load_data(int year , int id , vector<vector<Student>> &student ){
    Student &stud = student[year][id] ;
    ui->Profile->setItemText(0,QString::fromStdString(stud.name)) ;
    ui->Profile->setItemText(1,QString::fromStdString("MyProfile")) ;
}

void StudentPage::on_Profile_currentIndexChanged(int index)
{
    if(index==1)
        ui->scrollArea->setWidget( ptrFrame = new Frame );
    else
        ptrFrame->hide() ;
}

