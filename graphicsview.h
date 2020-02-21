

#pragma once
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene *scene = 0, QWidget *parent = 0);

    bool viewportEvent(QEvent *event) override;

private:
    qreal totalScaleFactor;
};
