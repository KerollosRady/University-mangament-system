#pragma once
#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include <QMainWindow>
#include <adminpage.h>
#include <studentpage.h>
#include <student.h>
#include <ctime>
QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow

{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_toolButton_20_clicked();
private:
    Ui::LoginPage *ui;
    StudentPage* ptrStudentPage  ;
    AdminPage* ptrAdminPage ;
    int last_year;
    vector<Course> course ;
    vector<vector<Student>> student ;
public :
    void load_data() ;
    void pre() ;
    void save_data() ;
};

#endif // LOGINPAGE_H
