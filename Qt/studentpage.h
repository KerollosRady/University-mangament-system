#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H
#pragma once
#include <QDialog>
#include <student.h>
#include <frame.h>
namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    void ProfileProperties();
    ~StudentPage();

private:
    Ui::StudentPage *ui;
    Student stud ;
    Frame * ptrFrame ;

public:
    void load_data(int year , int id , vector<vector<Student>>&student) ;
private slots:
    void on_Profile_currentIndexChanged(int index);
};

#endif // STUDENTPAGE_H
