#pragma once
#include <QDialog>
#include <newCourse.h>
#include "adminwelcome.h"
#include <QMainWindow>
#include <editCourse.h>
#include <newstudent.h>

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr, QMainWindow * loginpage= nullptr ,  vector<Course>*courses = nullptr,
                       vector<vector<Student>>* st = nullptr);
    ~AdminPage();

private slots:
    void on_logout_clicked();
    void on_NewCourse_clicked();
    void on_HomeButton_clicked();
    void on_EditCourse_clicked();    
    void on_NewStudent_clicked();

private:
    Ui::AdminPage *ui;
    newCourse * ptrCourse ;
    adminwelcome * welcome;
    QMainWindow * loginpage ;
    vector<Course>* courses ;
    EditCourse * ptrEdit;
    newStudent *newStd;
    vector<vector<Student>> * students;
public :
    void home() ;
};

