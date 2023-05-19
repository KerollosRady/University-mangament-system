#ifndef ADMINVIEWCOURSE_H
#define ADMINVIEWCOURSE_H

#include <QWidget>
#include <QListWidgetItem>
#include <Data.h>
#include <course.h>
namespace Ui {
class AdminViewCourse;
}

class AdminViewCourse : public QWidget
{
    Q_OBJECT

public:
    explicit AdminViewCourse(QWidget *parent = nullptr,Data * data =nullptr);
    ~AdminViewCourse();
    void additem_treewidget(int c) ;
    void additem_filter(QString s) ;
private slots:
    void on_fitler_clicked();
private:
    Ui::AdminViewCourse *ui;
    Data * data  ;
};

#endif // ADMINVIEWCOURSE_H
