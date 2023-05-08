#include "viewcourses.h"
#include "ui_viewcourses.h"
#include <debuging.h>
#include <ui_debuging.h>
#include <math.h>
#include <iomanip> // for std::setprecision(), std::fixed
#include <sstream>
ViewCourses::ViewCourses(QWidget *parent, Student * stud  , vector<Course> *course ) :
    QWidget(parent),
    ui(new Ui::ViewCourses)
{

    stud->ViewAllcourses(*course) ;

    //Progress courses
    ui->setupUi(this);
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(auto c : stud->progressCourses)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::fromStdString(to_string(c))) ;
        item->setText(1,QString::fromStdString(to_string(course->at(c).hours))) ;
        item->setText(2,QString::fromStdString(to_string(stud->courseGPA.at(c))))  ;
        item->setText(3,"False")  ;
        item->setText(4,QString::fromStdString(course->at(c).name));
        ui->treeWidget->addTopLevelItem(item) ;

    }
   // -------------------------------------------------------------------------------------

    // Finished Courses
    int i=0 ;
    for(auto c : stud->finishedCourses)
    {
        if(c==true){
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,QString::fromStdString(to_string(i))) ;
            item->setText(1,QString::fromStdString(to_string(course->at(i).hours))) ;
            ostringstream stream;
            stream  << fixed << setprecision(2) << stud->courseGPA.at(i);
            item->setText(2,QString::fromStdString(stream.str()))  ;
            item->setText(3,"True")  ;
            item->setText(4,QString::fromStdString(course->at(i).name));
            ui->treeWidget->addTopLevelItem(item) ;
        }
        i++ ;
    }
    ui->treeWidget->setStyleSheet("color : white ; ") ;
    ui->treeWidget->header()->setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
}

ViewCourses::~ViewCourses()
{
    delete ui;
}
