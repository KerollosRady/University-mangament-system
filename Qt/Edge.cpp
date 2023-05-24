#include <Edge.h>
Edge::Edge(Node * SourceNode ,Node * DestinationNode , QGraphicsView* view , QGraphicsItem* parent )
	:
    QGraphicsItem( parent ){
	setFlag( QGraphicsItem::ItemIsFocusable );
	setZValue( -1 );
    mSourceNode = SourceNode ;
    this->view = view ;
    mDestinationNode = DestinationNode  ;
}
void Edge::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
	//infrastructure for shape
	QPen graypen( Qt::gray );
	graypen.setWidth( 2 );
	QPen redpen( Qt::red );
	redpen.setWidth( 3 );

	painter->setPen( graypen );

	//Draw line
	//calculate positions between shapes of nodes
	//center of node + normalized vector of path * radius
    QVector2D pathVector = QVector2D( mDestinationNode->GetCenterPosition() - mSourceNode->GetCenterPosition() );

    QPointF source = mSourceNode->GetCenterPosition() + (pathVector.normalized().toPointF() * (100.0/2) );

    QPointF destination = mDestinationNode->GetCenterPosition() - (pathVector.normalized().toPointF() * (100.0/2));
    update() ;
    painter->drawLine( /*QPointF(0,0), QPointF(100,100)*/  source, destination );
    update() ;
	//Draw arrow
	//detect angle
    double angle = std::atan2( -pathVector.y(), pathVector.x() );
    // sin ( ceta - 60 )
    //create points and calculate rotation
    QPointF destArrowP1 = destination + QPointF( sin( angle - M_PI / 3 ) * 10, cos( angle - M_PI / 3 ) * 10 );
    QPointF destArrowP2 = destination + QPointF( sin( angle - M_PI + M_PI / 3 ) * 10, cos( angle - M_PI + M_PI / 3 ) * 10 );

    QPolygonF arrow;
    arrow.push_back( destination );
    arrow.push_back( destArrowP1 );
    arrow.push_back( destArrowP2 );
	painter->setBrush( Qt::gray );
    update();
    painter->drawPolygon( arrow );
    update();
}

QRectF Edge::boundingRect() const
{
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    QRect viewport_rect(0, 0, view->viewport()->width(), view->viewport()->height());
    return view->mapToScene(viewport_rect).boundingRect();
}

void Edge::mousePressEvent( QGraphicsSceneMouseEvent * event )
{
    update();
	QGraphicsItem::mousePressEvent( event );
    update();
}
void Edge::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
    update();
	QGraphicsItem::mouseReleaseEvent( event );
    update();
}
void Edge::mouseMoveEvent( QGraphicsSceneMouseEvent * event )
{
    update();
	QGraphicsItem::mouseMoveEvent( event );
    update();
}
