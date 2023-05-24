#include "studentpage.h"
#include "ui_studentpage.h"
#include <viewcourses.h>
#include <registerform.h>
#include <adminviewcourse.h>
#include <coursevisualize.h>
#include <studregpage.h>

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
void StudentPage::paint_current(QPushButton * b , int i){
    QString currentStyleSheet = b->styleSheet();
    // Modify the background color property in the stylesheet
    if(i==1)
        currentStyleSheet.replace("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);",
                                  "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(255, 255, 255), stop:1 rgb(53, 53, 53));");
    else
        currentStyleSheet.replace("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(255, 255, 255), stop:1 rgb(53, 53, 53));" ,
                                  "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);"
                                  );
    b->setStyleSheet(currentStyleSheet) ;
}
void StudentPage::paint_button(){
    for(auto item : this->children())
        if(QPushButton* button = qobject_cast<QPushButton*>(item))
            paint_current(button,0) ;
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
    paint_button() ;
    paint_current(ui->HomeButton , 1);
}


void StudentPage::on_MyCoursesButton_clicked()
{
    paint_button() ;
    paint_current(ui->MyCoursesButton , 1);

    ui->scrollArea->setWidget(new ViewCourses(nullptr, &data->student[year][id],&data->course,1)) ;
}


void StudentPage::on_GradeButton_clicked()
{
    paint_button() ;
    paint_current(ui->GradeButton , 1);

     ui->scrollArea->setWidget(new ViewCourses(nullptr, &data->student[year][id],&data->course,0)) ;
}


void StudentPage::on_RegisterButton_clicked()
{
     paint_button() ;
     paint_current(ui->RegisterButton , 1);

    QDate curDate = QDate::currentDate();
    if (curDate >= data->startRegDate && curDate <= data->endRegDate){
       ui->scrollArea->setWidget(new RegisterForm(nullptr,&data->course, &data->student[year][id])) ;
    }
    else {
       ui->scrollArea->setWidget(new StudRegPage(nullptr,data));
    }
}


void StudentPage::on_MyProfile_clicked()
{
    paint_button() ;
    paint_current(ui->MyProfile , 1);

     ui->scrollArea->setWidget(new Frame(nullptr,&data->student[year][id]));
}


void StudentPage::on_Logout_clicked()
{
     loginpage->show() ;
     this->hide() ;
}


void StudentPage::on_filterCourses_clicked()
{
     paint_button() ;
     paint_current(ui->filterCourses , 1);

    ui->scrollArea->setWidget(new AdminViewCourse(nullptr,data));
}


void StudentPage::on_DataVisualization_clicked()
{
    paint_button() ;
    paint_current(ui->DataVisualization , 1);

     ui->scrollArea->setWidget(new CourseVisualize(nullptr , data));
}

