#include "studentpage.h"
#include "ui_studentpage.h"
#include <viewcourses.h>
#include <registerform.h>
#include <adminviewcourse.h>
StudentPage::StudentPage(QWidget *parent , QMainWindow *loginpage , Data * data    ) :QDialog(parent),ui(new Ui::StudentPage)
{
    ui->setupUi(this);
    this->loginpage = loginpage ;
    this->data = data ;
    home() ;
}

StudentPage::~StudentPage()
{
    delete ui;
}

void StudentPage::load_data(int year , int id){
    this->year = year;
    this->id = id;
    ui->Name->setText(QString::fromStdString(data->student[year][id].name)) ;
    ui->Name->setReadOnly(true);
}


void StudentPage::on_HomeButton_clicked()
{
    home();
}
void StudentPage::home(){
    ui->scrollArea->setWidget(new FrameWelcome) ;
}


void StudentPage::on_MyCoursesButton_clicked()
{
    ui->scrollArea->setWidget(new ViewCourses(nullptr, &data->student[year][id],&data->course,1)) ;
}


void StudentPage::on_GradeButton_clicked()
{
     ui->scrollArea->setWidget(new ViewCourses(nullptr, &data->student[year][id],&data->course,0)) ;
}


void StudentPage::on_RegisterButton_clicked()
{
     ui->scrollArea->setWidget(new RegisterForm(nullptr,&data->course, &data->student[year][id])) ;
}


void StudentPage::on_MyProfile_clicked()
{
     ui->scrollArea->setWidget(new Frame(nullptr,&data->student[year][id]));
}


void StudentPage::on_Logout_clicked()
{
     loginpage->show() ;
     this->hide() ;
}


void StudentPage::on_RegisterButton_2_clicked()
{
     ui->scrollArea->setWidget(new AdminViewCourse(nullptr,data));
}

