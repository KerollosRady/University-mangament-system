#pragma once
#ifndef COURSEVISUALIZE_H
#define COURSEVISUALIZE_H
#include <QWidget>
#include <data.h>
#include <QMouseEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Node.h>
#include<QGraphicsLinearLayout>
#include <stack>
namespace Ui {
class CourseVisualize;
}

class CourseVisualize : public QWidget
{
    Q_OBJECT

public:
    explicit CourseVisualize(QWidget *parent = nullptr , Data * data = nullptr );
    void dfs1(int node , stack<int>&) ;
    void dfs2(int node,int lev ) ;
    ~CourseVisualize();
    vector<bool> vis ;
    Data *data ;
    QGraphicsScene* scene ;
    QGraphicsView* view   ;
    vector<Node*> item_node ;
    QPointF curr ;
private:
    Ui::CourseVisualize *ui;
};

#endif // COURSEVISUALIZE_H
