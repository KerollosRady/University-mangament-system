#include "viewcoursesofstudent.h"
#include "ui_viewcoursesofstudent.h"
ViewCoursesOfStudent::ViewCoursesOfStudent(QWidget *parent , Data * data ) :
    QWidget(parent),
    ui(new Ui::ViewCoursesOfStudent)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(5, 14, 43);");
    this->data  =data ;
    ui->StudentNamelineEdit_2->setReadOnly(true) ;
    hide_items() ;
    ui->Student_ID->setMaximum((2000+data->last_year)*10000+data->student[data->last_year].size());
    ui->progress->setCheckState(Qt::Checked) ;
    ui->finished->setCheckState(Qt::Checked) ;
    ui->treeWidget->setStyleSheet("color : white ; ") ;
    ui->treeWidget->header()->setStyleSheet("QHeaderView::section { background-color: #cccccc; color : black ;}");
}

ViewCoursesOfStudent::~ViewCoursesOfStudent()
{
    delete ui;
}

void ViewCoursesOfStudent::on_view_clicked()
{
    hide_items() ;
    int value = ui->Student_ID->value() ;
    int year = value/10000-2000 ;
    int id = value%10000 ;
    if(data->student[year].size()<=id)
    {
        return ;
    }
    stud = &data->student[year][id] ;
    ui->StudentNamelineEdit_2->setText(data->string_to_Qstring(stud->name)) ;
    filter() ;
    show_items() ;
}

void ViewCoursesOfStudent::hide_items(){
    ui->treeWidget->hide() ;
    ui->StudentNamelabel->hide() ;
    ui->StudentNamelineEdit_2->hide() ;
    ui->filter->hide() ;
    ui->save->hide() ;
}
void ViewCoursesOfStudent::show_items(){
    ui->treeWidget->show() ;
    ui->StudentNamelabel->show() ;
    ui->StudentNamelineEdit_2->show() ;
    ui->filter->show() ;
    ui->save->show() ;
}
void ViewCoursesOfStudent::filter(){
    ui->treeWidget->clear() ;
    if(ui->progress->checkState() == Qt::Checked)
        for(auto c : stud->progressCourses)
            show_course(c) ;
    if(ui->finished->checkState() == Qt::Checked)
        for(int i=0 ;i<data->course.size() ;i++)
            if(stud->finishedCourses[i])
                show_course(i) ;
}
void ViewCoursesOfStudent::show_course(int c ){
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    QDoubleSpinBox *Grade = new QDoubleSpinBox(ui->treeWidget);
    Grade->setRange(0,100) ;
    Grade->setValue(stud->courseGPA[c]*100/4);
    Grade->setStyleSheet("color : white ;") ;
    ui->treeWidget->setItemWidget(item, 0, Grade);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(1, (stud->finishedCourses[c]?(Qt::Checked):(Qt::Unchecked)));
    item->setText(2,QString::fromStdString(to_string(c)))  ;
    item->setText(3,QString::fromStdString(data->course[c].name)) ;
    ui->treeWidget->addTopLevelItem(item) ;
}

void ViewCoursesOfStudent::on_filter_clicked()
{
    filter() ;
}

void ViewCoursesOfStudent::on_save_clicked()
{

    int rowCount = ui->treeWidget->topLevelItemCount(); // the number of rows in the column
    set<int> s= set(stud->progressCourses.begin(),stud->progressCourses.end()) ;
    for (int row = 0; row < rowCount; ++row) {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(row);
        int c = item->text(2).toInt(nullptr ,10);
        qCritical()<<QString::fromStdString(to_string(c)) ;
        QDoubleSpinBox *spinBox = qobject_cast<QDoubleSpinBox*>(ui->treeWidget->itemWidget(item, 0)); // Get a pointer to the double spin box widget
        double grade = spinBox->value();
        qCritical()<<QString::fromStdString(to_string(grade)) ;
        stud->courseGPA[c] = grade ;
        stud->finishedCourses[c]= (item->checkState(1)==Qt::Checked) ;
        if(stud->finishedCourses[c] && s.find(c)!=s.end())
            s.erase(c) ;
        else if(!stud->finishedCourses[c])
            s.insert(c) ;
    }
    stud->progressCourses = vector(s.begin(),s.end()) ;
    // message "saved successfully"
}
void ViewCoursesOfStudent::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{
    if(column==1)
    {
        QDoubleSpinBox *Grade = new QDoubleSpinBox(ui->treeWidget);
        Qt::CheckState state = item->checkState(column); // Get the state of the item
        if (state == Qt::Checked) {
            Grade->setRange(50,100) ;
        } else {
            Grade->setRange(0,100) ;
        }
        ui->treeWidget->setItemWidget(item, 0, Grade);
    }
}

