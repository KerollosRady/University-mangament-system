#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

#include <QDialog>
#include "course.h"
#include "student.h"
#include <data.h>
#include <Qtimer>

namespace Ui {
class newStudent;
}

class newStudent : public QDialog
{
    Q_OBJECT

public:
    explicit newStudent(QWidget *parent = nullptr, Data* data = nullptr);
    ~newStudent();

private slots:
    void on_courseList_currentIndexChanged(int index);

    void on_ok_clicked();

    void on_Add_clicked();

    void on_clear_clicked();

private:
    Ui::newStudent *ui;
    Data* data;
    vector<float> enteredGrades;
    bool isFloat(std::string);
    void clear();
};

#endif // NEWSTUDENT_H
