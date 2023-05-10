#include "studentpage.h"
#include "ui_studentpage.h"
#include <viewcourses.h>
#include <registerform.h>
#include <adminviewcourse.h>
StudentPage::StudentPage(QWidget *parent , QMainWindow *loginpage , vector<Course>* courses, filtercourses * filter_courses    ) :QDialog(parent),ui(new Ui::StudentPage)
{
    ui->setupUi(this);
    this->loginpage = loginpage ;
    this->courses= courses ;
    this->filter_courses = filter_courses ;
    home() ;
}

StudentPage::~StudentPage()
{
    delete ui;
}

void StudentPage::load_data(int year , int id , vector<vector<Student>> &student){
    this->stud = &student[year][id] ;
    ui->Name->setText(QString::fromStdString(stud->name)) ;
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
    ui->scrollArea->setWidget(new ViewCourses(nullptr, stud,courses,1)) ;
}


void StudentPage::on_GradeButton_clicked()
{
     ui->scrollArea->setWidget(new ViewCourses(nullptr, stud,courses,0)) ;
}


void StudentPage::on_RegisterButton_clicked()
{
     ui->scrollArea->setWidget(new RegisterForm(nullptr,courses, stud)) ;
}


void StudentPage::on_MyProfile_clicked()
{
     ui->scrollArea->setWidget(new Frame(nullptr,stud));
}


void StudentPage::on_Logout_clicked()
{
     loginpage->show() ;
     this->hide() ;
}


void StudentPage::on_RegisterButton_2_clicked()
{
     ui->scrollArea->setWidget(new AdminViewCourse(nullptr,filter_courses,courses));
}

