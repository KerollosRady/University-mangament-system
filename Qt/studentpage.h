#pragma once
#include <QDialog>
#include <student.h>
#include <frame.h>
#include <QScrollArea>
#include <framewelcome.h>
#include <ui_loginpage.h>
#include <data.h>
namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr,QMainWindow *loginpage = nullptr,Data * data = nullptr );
    void ProfileProperties();
    ~StudentPage();
    void paint_button() ;
    void paint_current(QPushButton * b , int i) ;
private:
    Ui::StudentPage *ui;
    QMainWindow *loginpage ;
    Data* data ;
    int year,id;
public:
    void load_data(int year , int id) ;
    void home() ;
private slots:
    void on_HomeButton_clicked();
    void on_MyCoursesButton_clicked();
    void on_GradeButton_clicked();
    void on_RegisterButton_clicked();
    void on_MyProfile_clicked();
    void on_Logout_clicked();
    void on_DataVisualization_clicked();
    void on_filterCourses_clicked();
};

