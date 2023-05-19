#pragma once

#ifndef NODE_H
#define NODE_H
#include <data.h>
#include <functional>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
class Node : public QGraphicsItem
{
public:
    Node( int number, QGraphicsItem* parent = NULL , Data * data = nullptr );
    QPointF GetCenterPosition() const;
	bool GetIsPressed() const
	{
		return bIsPressed;
	}
    Data * data ;
protected:
	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) override;
	virtual QRectF boundingRect() const override;
	virtual void mousePressEvent( QGraphicsSceneMouseEvent * event ) override;
	virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * event ) override;
	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent *event ) override;
private:
	//animation states
	void Start01();
	void Start02();
	void End01();

protected:
	const int mNumber;
    bool bIsPressed;
};


#endif //NODE_H
