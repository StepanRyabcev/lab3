#ifndef SCENECARRY_H
#define SCENECARRY_H
#include <QGraphicsScene>
#include "MyList.h"

class SceneCarry
{
public:
    QGraphicsScene *sc;
    MyList<QGraphicsPixmapItem*> *itm;
    SceneCarry();
};

#endif // SCENECARRY_H
