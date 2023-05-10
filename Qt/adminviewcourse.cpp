#include "adminviewcourse.h"
#include "ui_adminviewcourse.h"

AdminViewCourse::AdminViewCourse(QWidget *parent ,Data * data) :
    QWidget(parent),
    ui(new Ui::AdminViewCourse)
{
    ui->setupUi(this);
    this->data = data ;
        QListWidgetItem *item1 = new QListWidgetItem(QString::fromStdString("Instructor Name"), ui->ListWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
        item1 = new QListWidgetItem(QString::fromStdString("Hours"), ui->ListWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
        item1 = new QListWidgetItem(QString::fromStdString("Electivity"), ui->ListWidget);
        item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
        item1->setCheckState(Qt::Unchecked);
        int i=0 ;
        for(auto c : data->course){
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->tree_Widget);
            item->setText(0,QString::fromStdString(to_string(i)))  ;
            item->setText(1,QString::fromStdString(c.name)) ;
            item->setText(2,QString::fromStdString(c.instructor)) ;
            item->setText(3,QString::fromStdString((c.isElective?"True":"False")));
            item->setText(4,QString::fromStdString(to_string(c.hours)));
            string s ="" ;
            for(auto a : c.PreReqCourses)
                s+=to_string(a)+" " ;
            item->setText(5,QString::fromStdString(s));
            ui->tree_Widget->addTopLevelItem(item) ;
            i++;
        }
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
        int electivity , hours  ;
        string instructor  ;
        if(selected->item(2)->checkState()== Qt::Checked)
            electivity = ui->electivity->isChecked() ;
        else
                electivity = -1 ;
    if(selected->item(1)->checkState()== Qt::Checked)
                hours = ui->hours->value() ;
    else
                hours = -1 ;
    if(selected->item(0)->checkState()== Qt::Checked)
                instructor = ui->instractor->text().toStdString() ;
    else
                instructor = "-1" ;
    set<int> s = data->filter(electivity , hours , instructor ) ;
        for(auto c : s){
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
        ui->tree_Widget->setStyleSheet("color : white ; ") ;
        ui->tree_Widget->header()->setStyleSheet("QHeaderView::section { background-color: #eee; color : black ;}");
}

