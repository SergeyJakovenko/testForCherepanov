

#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsObject>

//! [0]
class Mouse : public QGraphicsObject
{
    Q_OBJECT

public:
    Mouse();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    qreal angle;
    qreal speed;
    qreal mouseEyeDirection;
    QColor color;
};
//! [0]

#endif
