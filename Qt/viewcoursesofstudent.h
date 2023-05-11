#ifndef VIEWCOURSESOFSTUDENT_H
#define VIEWCOURSESOFSTUDENT_H

#include <QWidget>
#include<data.h>
#include <qtreewidget.h>
namespace Ui {
class ViewCoursesOfStudent;
}

class ViewCoursesOfStudent : public QWidget
{
    Q_OBJECT

public:
    explicit ViewCoursesOfStudent(QWidget *parent = nullptr , Data * data = nullptr );
    ~ViewCoursesOfStudent();

private slots:
    void on_view_clicked();
    void on_filter_clicked();

    void on_save_clicked();

    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::ViewCoursesOfStudent *ui;
    Data * data ;
    Student * stud  ;
public :
    void hide_items() ;
    void show_items() ;
    void filter() ;
    void show_course(int c) ;
};

#endif // VIEWCOURSESOFSTUDENT_H
