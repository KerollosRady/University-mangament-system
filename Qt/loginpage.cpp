
#include "loginpage.h"
#include "ui_loginpage.h"
#include <algorithm>
#include <math.h>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ptrStudentPage = new StudentPage() ;
    ptrAdminPage   = new AdminPage() ;
}

void LoginPage::load_data(){
     Course c1;
     c1.insert("Programming 1", "Dr.Hanan", 500, 3,{});
     Course c2;
     c2.insert("Programming 2", "Dr.Hanan", 1000, 6, { 0 });
     Course c3;
     c3.insert("Programming 3", "Dr.Hanan", 2000, 12, { 0,1 });
     course = {c1,c2,c3} ;
     student.resize(last_year+1) ;
     student[last_year]={
                               Student(2023, 0, "abdo", 3),
                               Student(2023, 1, "kero", 3),
                               Student(2023, 2, "bebo", 3)};
     for(auto std : student[23])
         cout<<std.getEmail()<<' '<<std.getPassword()<<endl ;
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
    // "yearid@cis.asu.eg"
    QString usr = ui->username_11->text() ;
    QString pass= ui->password_11->text() ;
    if(usr=="Admin" &&  pass == "Admin123"){
        this->hide()  , ptrAdminPage->show();
    }
    else if(usr.size()!=19)
         return ;
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
             id<student[year].size() && student[year][id].getPassword() == pass.toStdString())
            this->hide() , ptrStudentPage->show() ;
    }
}

void LoginPage::save_data(){

}
