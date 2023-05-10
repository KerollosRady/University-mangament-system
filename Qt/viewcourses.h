#ifndef VIEWCOURSES_H
#define VIEWCOURSES_H
#include <QWidget>
#include <student.h>

namespace Ui {
class ViewCourses;
}

class ViewCourses : public QWidget
{
    Q_OBJECT

public:
    explicit ViewCourses(QWidget *parent = nullptr , Student* stud = nullptr , vector<Course> *course = nullptr , bool current   = 0);
    ~ViewCourses();

private:
    Ui::ViewCourses *ui;
};

#endif // VIEWCOURSES_H
