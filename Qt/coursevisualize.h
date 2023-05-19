#pragma once
#ifndef COURSEVISUALIZE_H
#define COURSEVISUALIZE_H
#pragma once
#include <QWidget>
#include <data.h>
#include <QMouseEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Node.h>
#include <QGraphicsLinearLayout>
#include <stack>
#include <QPushButton>
namespace Ui {
class CourseVisualize;
}

class CourseVisualize : public QWidget
{
    Q_OBJECT

public:
    explicit CourseVisualize(QWidget *parent = nullptr , Data * data = nullptr  , QPushButton * save = nullptr  , QPushButton * auto_generate = nullptr  );
    void dfs(int node ) ;
    void generate() ;
    ~CourseVisualize();
    vector<bool> vis ;
    Data *data ;
    QGraphicsScene* scene ;
    QGraphicsView* view   ;
    vector<Node*> item_node ;
    QPointF curr ;
    QPushButton * save ;
    QPushButton * auto_generate ;
    stack<int> s  ;
public slots :
    void save_button() ;
    void auto_generate_button() ;
private:
    Ui::CourseVisualize *ui;
};

#endif // COURSEVISUALIZE_H
