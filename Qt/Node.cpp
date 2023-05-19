#include <Node.h>
#include <QPainter>
Node::Node( int number , QGraphicsItem* parent , Data * data):
    QGraphicsItem( parent ),
    mNumber( number ),bIsPressed( false )
{
    this->data =data ;
    setFlag( QGraphicsItem::ItemIsMovable );
}

QPointF Node::GetCenterPosition() const
{
	return pos() + boundingRect().center();
}

void Node::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
	//get node's bounding rectangle
	QRectF rect = boundingRect();
	//infrastructure for shape
	QPen grayPen( Qt::GlobalColor::gray );
	grayPen.setWidth( 6 );
	QPen blackPen( Qt::GlobalColor::black );
	blackPen.setWidth( 6 );

	if( bIsPressed )
	{
		painter->setPen( blackPen );
	}
	else
	{
		painter->setPen( grayPen );
	}

	//draw shape
	painter->drawEllipse( rect );

	//draw texture
	QPixmap texture = QPixmap( "Node50x50.png" );
    painter->drawPixmap( 0, 0, 100, 100, texture );

	//draw number
	QFont font;
	font.setWeight( QFont::Bold );
    painter->setFont( font );
    painter->drawText ( rect, Qt::AlignCenter | Qt::AlignVCenter, QString::fromStdString(data->course[mNumber].name));
    update();
    update();
}
QRectF Node::boundingRect() const
{
    return QRectF( 0, 0, 100, 100 );
}

void Node::mousePressEvent( QGraphicsSceneMouseEvent * event )
{
	bIsPressed = true;
    update();
    update();
	QGraphicsItem::mousePressEvent( event );
}
void Node::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
	bIsPressed = false;
    update();
    update();
	QGraphicsItem::mouseReleaseEvent( event );
}
void Node::mouseMoveEvent( QGraphicsSceneMouseEvent * event )
{
    update();
    update();
	QGraphicsItem::mouseMoveEvent( event );
}
