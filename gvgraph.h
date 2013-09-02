#ifndef GVGRAPH_H
#define GVGRAPH_H

#include <QVector>
#include <QMap>
#include <QString>
#include <QDebug>
#include <QGraphicsScene>
#include <gvc.h>
#include "entityicon.h"


class GVGraph
{

public:

    GVGraph();
    void openGraph();
    void closeGraph();
    void layout(QString layoutAlgo);
    Agnode_t* addNode(EntityIcon* node);
    Agedge_t* addEdge(EntityIcon* n1 ,EntityIcon* n2);
    ~GVGraph();

private:

    QMap<EntityIcon*,Agnode_t*> nodes;
    QVector<Agedge_t*>  edges;
    Agraph_t* graph;
    GVC_t *gvc;

};


#endif // GVGRAPH_H
