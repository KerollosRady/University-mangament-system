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
    stack<int> s  ; // toplogical sort
    for(int i=0 ;i<data->course.size() ;i++)
        if(!vis[i])
            dfs1(i,s) ;
    int lev=0  ;
    while(!s.empty()){
        if(vis[s.top()])
            dfs2(s.top(),lev) ;
        s.pop() ;
    }
}

CourseVisualize::~CourseVisualize()
{
    delete ui;
    delete scene ;
    delete view ;
}
void CourseVisualize::dfs1( int node , stack<int>&s )
{
    vis[node]=true ;
    item_node[node] = new Node(node,nullptr,data) ;
    scene->addItem(item_node[node]) ;
    for(auto child : data->course[node].PreReqCourses){
        if(!vis[child])
            dfs1(child,s) ;
        Edge *edge = new Edge(item_node[node],item_node[child],view) ;
        scene->addItem(edge) ;
    }
    s.push(node) ;
}
void CourseVisualize::dfs2( int node ,int lev )
{
    queue<int> q ;
    q.push(node) ;
    for(int sz ; (sz = q.size()) ;lev++)
    {
        int x = 500 - (((sz+1)/2-1)*200+100*(!(sz&1))) ;
        int y = lev*200+10 ;
        for(int i=0 ;i<sz ;i++){
            int node = q.front();
            item_node[node]->setPos(x,y) ;
            for(auto child: data->course[node].PreReqCourses)
                q.push(child) ;
            x+=200 ;
            vis[node]=false ;
            q.pop() ;
        }
    }
}
