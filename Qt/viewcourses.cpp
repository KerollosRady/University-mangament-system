#include "viewcourses.h"
#include "ui_viewcourses.h"
#include <debuging.h>
#include <ui_debuging.h>
#include <math.h>
#include <iomanip> // for std::setprecision(), std::fixed
#include <sstream>
ViewCourses::ViewCourses(QWidget *parent, Student * stud  , vector<Course> *course , bool current   ) :
    QWidget(parent),
    ui(new Ui::ViewCourses)
{
    ui->setupUi(this);
    if(current){
        //Progress courses
        ui->treeWidget->setColumnHidden(0, true) ;
        for(auto c : stud->progressCourses)
        {
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
            string gpa = to_string(stud->courseGPA.at(c)) ;
            for(int i=0 ;i<3 ;i++)
                gpa.pop_back() ;
            item->setText(0,QString::fromStdString(gpa))  ;
            item->setText(1,QString::fromStdString(to_string(c))) ;
            item->setText(2,QString::fromStdString(to_string(course->at(c).hours))) ;
            item->setText(3,QString::fromStdString(course->at(c).name));
            ui->treeWidget->addTopLevelItem(item) ;

        }
    }
    else{
        // Finished Courses
        int codeCourse=0 ;
        for(auto c : stud->finishedCourses)
        {
            if(c==true){
                QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
                ostringstream stream;
                stream  << fixed << setprecision(2) << stud->courseGPA.at(codeCourse);
                string s = stream.str() ;
                for(int i=0 ;i<3 ;i++)
                    s.pop_back() ;
                item->setText(0,QString::fromStdString(s))  ;
                item->setText(1,QString::fromStdString(to_string(codeCourse))) ;
                item->setText(2,QString::fromStdString(to_string(course->at(codeCourse).hours))) ;
                item->setText(3,QString::fromStdString(course->at(codeCourse).name));
                ui->treeWidget->addTopLevelItem(item) ;
            }
            codeCourse++ ;
        }
    }
    ui->treeWidget->setStyleSheet("color : white ; ") ;
    ui->treeWidget->header()->setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
}

ViewCourses::~ViewCourses()
{
    delete ui;
}
