

#include "graphicsview.h"
#include "mouse.h"

#include <QtWidgets>

#include <math.h>

static const int MouseCount = 7;

//! [0]
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
//! [0]

//! [1]
    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
//! [1] //! [2]
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
//! [2]

//! [3]
    for (int i = 0; i < MouseCount; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                      ::cos((i * 6.28) / MouseCount) * 200);
        scene.addItem(mouse);
    }
//! [3]

//! [4]
    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/cheese.jpg"));
//! [4] //! [5]
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//! [5] //! [6]
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice"));
    view.showFullScreen();
    view.setWindowFlags(Qt::CustomizeWindowHint);
    view.showNormal();


    return app.exec();
}
//! [6]
