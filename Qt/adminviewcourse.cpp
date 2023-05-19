#include "adminviewcourse.h"
#include "ui_adminviewcourse.h"
AdminViewCourse::AdminViewCourse(QWidget *parent ,Data * data) :
    QWidget(parent),
    ui(new Ui::AdminViewCourse)
{
    ui->setupUi(this);
    this->data = data ;
    additem_filter("Instructor") ;
    additem_filter("Hours") ;
    additem_filter("Electivity") ;
        int i=0 ;
        for(auto c : data->course)
            additem_treewidget(i++) ;
        ui->tree_Widget->setStyleSheet("color : white ; ") ;
        ui->tree_Widget->header()->setStyleSheet("QHeaderView::section { background-color: #eee; color : black ;}");
}

AdminViewCourse::~AdminViewCourse()
{
    delete ui;
}

void AdminViewCourse::on_fitler_clicked()
{
        QListWidget * selected = ui->ListWidget ;
        ui->tree_Widget->clear() ;
        int electivity =-1, hours=-1  ;
        string instructor ="-1"  ;
        if(selected->item(2)->checkState()== Qt::Checked)
            electivity = (ui->electivity->isChecked()==true);
    if(selected->item(1)->checkState()== Qt::Checked)
            hours = ui->hours->value() ;
    if(selected->item(0)->checkState()== Qt::Checked)
            instructor = ui->instractor->text().toStdString() ;
    vector<int> s = data->filter(electivity , hours , instructor ) ;
        for(auto c : s)
            additem_treewidget(c);
}

void AdminViewCourse::additem_treewidget(int c)
{
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->tree_Widget);
        item->setText(0,QString::fromStdString(to_string(c)))  ;
        item->setText(1,QString::fromStdString(data->course[c].name)) ;
        item->setText(2,QString::fromStdString(data->course[c].instructor)) ;
        item->setText(3,QString::fromStdString((data->course[c].isElective ? "True" : "False" )));
        item->setText(4,QString::fromStdString(to_string(data->course[c].hours)));
        string s ="" ;
        for(auto a : data->course[c].PreReqCourses)
            s+=to_string(a)+" " ;
        item->setText(5,QString::fromStdString(s));
        ui->tree_Widget->addTopLevelItem(item) ;
}
void AdminViewCourse::additem_filter(QString s )
{
        QListWidgetItem *item1 = new QListWidgetItem(s, ui->ListWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
}



