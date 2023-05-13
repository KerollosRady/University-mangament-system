#include "coursevisualize.h"
#include "ui_coursevisualize.h"

CourseVisualize::CourseVisualize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CourseVisualize)
{
    ui->setupUi(this);
}

CourseVisualize::~CourseVisualize()
{
    delete ui;
}
