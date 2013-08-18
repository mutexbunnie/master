#ifndef GVGRAPH_H
#define GVGRAPH_H

#include <gvc.h>
#include <QVector>
#include <QMap>
#include <QString>
#include "entityicon.h"

class GVGraph
{

QMap<EntityIcon*,Agnode_t*> nodes;
QVector<Agedge_t*>  edges;
Agraph_t* graph;


//Agsym_t *a;
GVC_t *gvc;
public:
GVGraph();


void openGraph();
void closeGraph();
void layout(QString layoutAlgo);
Agnode_t* addNode(EntityIcon* node);
Agedge_t* addEdge(EntityIcon* n1 ,EntityIcon* n2);

~GVGraph();

};


#endif // GVGRAPH_H
