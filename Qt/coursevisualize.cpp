#pragma once
#include <Edge.h>
#include <coursevisualize.h>
#include <stack>
#include <ui_coursevisualize.h>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QPointF>
#include <queue>
#include <QPushButton>
CourseVisualize::CourseVisualize(QWidget *parent , Data * data, QPushButton * save , QPushButton * auto_generate ) :
    QWidget(parent),
    ui(new Ui::CourseVisualize)
{
    ui->setupUi(this);
    this->data = data ;
    item_node.resize(data->course.size(),nullptr);
    vis.resize(data->course.size(),false) ;
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    // Create the content widget and layout
    QWidget* contentWidget = this;
    QVBoxLayout* layout = new QVBoxLayout(contentWidget);
    layout->addWidget(view);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    for(int i=0 ;i<data->course.size() ;i++)
        if(!vis[i])
            dfs(i) ;
    ui->message->hide() ;
    ui->message->raise() ;
    this->save = save ;
    this->auto_generate = auto_generate ;
    if(save!=nullptr){
        save->show() ;
        auto_generate->show() ;
        connect(save, &QPushButton::clicked, this, &CourseVisualize::save_button);
        connect(auto_generate, &QPushButton::clicked, this, &CourseVisualize::auto_generate_button);
    }
    for(int i=0 ;i<data->course.size() ;i++)
        item_node[i]->setPos(data->course[i].x , data->course[i].y) ;
}
CourseVisualize::~CourseVisualize()
{
    if(save!=nullptr){
        save->hide() ;
        auto_generate->hide() ;
    }
    delete ui;
    delete scene ;
    delete view ;
}
void CourseVisualize::dfs( int node )
{
    vis[node]=true ;
    item_node[node] = new Node(node,nullptr,data) ;
    scene->addItem(item_node[node]) ;
    for(auto child : data->course[node].PreReqCourses){
        if(!vis[child])
            dfs(child) ;
        Edge *edge = new Edge(item_node[node],item_node[child],view) ;
        scene->addItem(edge) ;
    }
    s.push(node) ;
}
void CourseVisualize::save_button()
{
    for(int i=0 ;i<data->course.size() ;i++)
        data->course[i].x = item_node[i]->pos().x() ,
            data->course[i].y = item_node[i]->pos().y()  ;
    ui->message->show();
    QTimer::singleShot(1000, this, [=]() {
        ui->message->hide();
    });
}
void CourseVisualize::auto_generate_button(){
    generate() ;
}
void CourseVisualize::generate(){
    QPointF curr(10,10) ;
    int cnt =0 ;
    bool flag =true ;
    stack<int> tmp = s ;
    while(!s.empty()){
        if(cnt%5==0 && cnt){
            curr.setY(curr.y()+180);
            if(flag)
                curr.setX(60) ;
            else
                curr.setX(10) ;
            flag = !flag ;
        }
        cnt++ ;
        item_node[s.top()]->setPos(curr);
        curr.setX(curr.x()+180);
        s.pop() ;
    }
    s = tmp ;
}
