#include "loginpage.h"
#include "ui_loginpage.h"
#include <algorithm>
#include <math.h>
#include <QFile>
#include <QTextStream>
#include <debuging.h>
#include <ui_debuging.h>
#include <QPushButton>
LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ptrStudentPage = new StudentPage(nullptr, this, &data) ;
    ptrAdminPage   = new AdminPage(nullptr,this, &data) ;
    pre() ;
    show();
    ui->IncorrectEmail->hide();
}
void LoginPage::load_data(){
    //data.student.resize(last_year+1);
    data.LoadDataFromStudent() ;
    data.LoadDataFromCourse() ;
    //qCritical()<<QString::fromStdString(data.student[last_year][0].getPassword());
}
void LoginPage::pre(){
     // get current system time
     time_t now = time(0);
     // convert to local time
     tm *ltm = localtime(&now);
     // get current year
     last_year = ltm->tm_year-100;
     data.last_year = last_year ;
     load_data() ;
}
LoginPage::~LoginPage()
{
     save_data() ;
    delete ui;
    delete ptrAdminPage ;
    delete ptrStudentPage ;
}
void LoginPage::on_toolButton_20_clicked()
{
    QString usr = ui->username_11->text() ;
    QString pass= ui->password_11->text() ;
    if(usr=="Admin" &&  pass == "Admin123"){
         ptrAdminPage->home(), ptrAdminPage->show() , this->hide();
         ui->IncorrectEmail->hide();
    }
    else if(usr.size()!=19)
         ui->IncorrectEmail->show();
    else
    {
         string s = "@cis.asu.eg" ;
         bool ok = true ;
         for(int i=18; i>7 && ok;i--)
            ok&=(usr[i]==s.back()) , s.pop_back() ;
         for(int i=0 ;i<8 && ok ;i++)
            ok&= usr[i].isDigit();
         if(!ok)
            return void(ui->IncorrectEmail->show());
         int year = 0 , id = 0  ;
         for(int i=0 ;i<4 ;i++)
            year+=pow(10,4-i-1)* usr[i].digitValue() ;
         for(int i=4 ;i<8 ;i++)
            id+=pow(10,8-i-1)*usr[i].digitValue() ;
         year-=2000 ;
         if( year>=0 && year<=last_year && id>=0 &&
             id<data.student[year].size() && data.student[year][id].getPassword() == pass.toStdString() ){
             ptrStudentPage->load_data(year,id) ;
            ui->IncorrectEmail->hide();
             ptrStudentPage->home() , ptrStudentPage->show(), this->hide() ;
            ui->IncorrectEmail->hide();
            ptrStudentPage->show(), this->hide();
         }
         else
         {
            ui->IncorrectEmail->show();
         }
    }
}

void LoginPage::save_data(){
    cout<<"done" ;
    data.UploadDataToCourse() ;
    data.UploadDataToStudent() ;
}
