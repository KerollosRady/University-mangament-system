#ifndef EDITCOURSE_H
#define EDITCOURSE_H

#include <QDialog>
#include <course.h>
#include <data.h>
#include <QTimer>
namespace Ui {
class EditCourse;
}

class EditCourse : public QDialog
{
    Q_OBJECT

public:
    explicit EditCourse(QWidget *parent = nullptr, Data* data = nullptr);
    void clear();
    void invalidInputData(int);
    bool isInt(std::string);
    bool dfsCycle(int cur, vector<bool> &vis);
    ~EditCourse();

private slots:
    void on_courseList_currentIndexChanged(int index);


    void on_clear_clicked();

    void on_Edit_clicked();

private:
    Ui::EditCourse *ui;
    Data* data;
};

#endif // EDITCOURSE_H
