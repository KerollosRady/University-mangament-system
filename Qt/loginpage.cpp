#include "loginpage.h"
#include "ui_loginpage.h"
#include <algorithm>
#include <math.h>
#include <QFile>
#include <QTextStream>
#include <debuging.h>
#include <ui_debuging.h>

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
    QFile file("../Qt/Courses.txt") ;
    /*
    name
    instructore
    MaxNumOfStud
    hours
    PreReqCourses
    */
    if(!file.exists() || !file.open(QIODevice::ReadOnly)){
        qCritical()<<file.errorString()<<el ;
        return ;
    }
    QTextStream stream (&file) ;
    while(!stream.atEnd()){
        QString line[5]  ;
        for(int i=0 ;i<5 ;i++){
            line[i] = stream.readLine()  ;
            qCritical()<<line[i]<<el ;
            }
        set<int> s;
        string snum ="";
        for(int i=0 ;i<line[4].size() ;i++)
        {
            if(!line[4][i].isDigit())
            {
                s.insert(stoi(snum)) ;
                snum="" ;
                continue ;
            }
            snum+=line[4][i].toLatin1();
        }
        if(!snum.empty())
            s.insert(stoi(snum)) ;
        Course c ;
        c.insert(line[0].toStdString(),line[1].toStdString(),line[2].toInt(),line[3].toInt(),s) ;
        c.isElective = true ;
        data.course.push_back(c) ;
    }
    for(auto c : data.course)
        c.DisplayData() ;
     data.student.resize(last_year+1) ;
     data.student[last_year]={
                               Student(2023, 0, "abdo", 100,"Faculty of Computer and Information Sciences"),
                               Student(2023, 1, "kero", 100,"Faculty of Computer and Information Sciences"),
                               Student(2023, 2, "bebo", 100,"Faculty of Computer and Information Sciences")};
     for (auto &s : data.student[last_year]){
        s.progressCourses = {0,1,2} ;
        cout<<s.getEmail()<<' '<<s.getPassword()<<el ;
     }
}
void LoginPage::pre(){
     // get current system time
     time_t now = time(0);
     // convert to local time
     tm *ltm = localtime(&now);
     // get current year
     last_year = 1900 + ltm->tm_year - 2000;
     load_data() ;
}
LoginPage::~LoginPage()
{
    delete ui;
    delete ptrAdminPage ;
    delete ptrStudentPage ;
}
void LoginPage::on_toolButton_20_clicked()
{
    QString usr = ui->username_11->text() ;
    QString pass= ui->password_11->text() ;
    if(usr=="" &&  pass == ""){
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
            return ;
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

}
