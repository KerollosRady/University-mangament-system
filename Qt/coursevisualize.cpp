#include <Edge.h>
#include <coursevisualize.h>
#include <stack>
#include <ui_coursevisualize.h>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QPointF>
#include <queue>
CourseVisualize::CourseVisualize(QWidget *parent , Data * data) :
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
    stack<int> s  ;
    for(int i=0 ;i<data->course.size() ;i++)
        if(!vis[i])
            dfs(i,s) ;
    QPointF curr(10,10) ;
    int cnt =0 ;
    bool flag =true ;
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
    view->setMinimumHeight(curr.y()+180) ;
}

CourseVisualize::~CourseVisualize()
{
    delete ui;
    delete scene ;
    delete view ;
}
void CourseVisualize::dfs( int node , stack<int>&s )
{
    vis[node]=true ;
    item_node[node] = new Node(node,nullptr,data) ;
    scene->addItem(item_node[node]) ;
    for(auto child : data->course[node].PreReqCourses){
        if(!vis[child])
            dfs(child,s) ;
        Edge *edge = new Edge(item_node[node],item_node[child],view) ;
        scene->addItem(edge) ;
    }
    s.push(node) ;
}
