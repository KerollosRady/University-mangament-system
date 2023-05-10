#ifndef ADMINVIEWCOURSE_H
#define ADMINVIEWCOURSE_H

#include <QWidget>
#include <QListWidgetItem>
#include <filtercourses.h>
#include <course.h>
namespace Ui {
class AdminViewCourse;
}

class AdminViewCourse : public QWidget
{
    Q_OBJECT

public:
    explicit AdminViewCourse(QWidget *parent = nullptr,filtercourses * filter_courses =nullptr , vector<Course> * courses  = nullptr );
    ~AdminViewCourse();

private slots:
    void on_fitler_clicked();

private:
    Ui::AdminViewCourse *ui;
    filtercourses * filter_courses  ;
    vector<Course> * courses ;
};

#endif // ADMINVIEWCOURSE_H
