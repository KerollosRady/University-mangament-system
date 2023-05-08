#pragma once
#include <QDialog>
#include <student.h>
#include <frame.h>
#include <QScrollArea>
#include <framewelcome.h>
#include <ui_loginpage.h>
namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr,QMainWindow *loginpage = nullptr , vector<Course>* courses  = nullptr );
    void ProfileProperties();
    ~StudentPage();

private:
    Ui::StudentPage *ui;
    Student *stud ;
    vector<Course>* courses ;
    QMainWindow *loginpage ;
public:
    void load_data(int year , int id , vector<vector<Student>>&student) ;
    void home() ;
private slots:
    void on_Profile_currentIndexChanged(int index);
    void on_pushButton_5_clicked();
    void on_HomeButton_clicked();
    void on_MyCoursesButton_clicked();
};

