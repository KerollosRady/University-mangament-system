#ifndef VIEWSTUDENT_H
#define VIEWSTUDENT_H

#include <QDialog>
#include <course.h>
#include <student.h>

namespace Ui {
class viewStudent;
}

class viewStudent : public QDialog
{
    Q_OBJECT

public:
    explicit viewStudent(QWidget *parent = nullptr , vector<Course>* courses = nullptr,
                         vector<vector<Student>>*st = nullptr);
    ~viewStudent();

private slots:
    void on_courseList_currentIndexChanged(int index);

private:
    Ui::viewStudent *ui;
    vector<vector<Student>> * students;
    vector<Course> * courses;
};

#endif // VIEWSTUDENT_H
