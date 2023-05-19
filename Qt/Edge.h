#pragma once
#ifndef EDGE_H
#define EDGE_H
#include <QtGui>
#include <Node.h>
#include <QGraphicsView>
class Node;

class Edge : public QGraphicsItem
{
public:
    Edge(Node * SourceNode = nullptr ,Node * DestinationNode=nullptr ,
         QGraphicsView* view  = nullptr , QGraphicsItem* parent = NULL );
protected:
	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) override;
    virtual QRectF boundingRect() const override;
	virtual void mousePressEvent( QGraphicsSceneMouseEvent * event ) override;
	virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * event ) override;
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent *event ) override;
protected:
	Node* mSourceNode;
	Node* mDestinationNode;
    QGraphicsView* view   ;
};


#endif //EDGE_H
