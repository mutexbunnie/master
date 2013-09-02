#include "gvgraph.h"

GVGraph::GVGraph() {}


void GVGraph::openGraph()
{
    gvc = gvContext();
    graph= agopen("Graph", AGDIGRAPHSTRICT);
}

GVGraph::~GVGraph() {}

void GVGraph::closeGraph()
{
    gvFreeLayout(gvc, graph);
    agclose(graph);
    gvFreeContext(gvc);
}


Agnode_t* GVGraph::addNode(EntityIcon* node)
{

   Agnode_t* tmp_Node = agnode(graph, (char*)node->getUidValue().toStdString().c_str());
   nodes.insert(node,tmp_Node);

   return tmp_Node;
}

Agedge_t* GVGraph::addEdge(EntityIcon* n1 , EntityIcon* n2)
{

   Agnode_t* tmp_Node1 =nodes.value(n1);
   Agnode_t* tmp_Node2 =nodes.value(n2);

   Agedge_t* tmp_edge = agedge(graph, tmp_Node1, tmp_Node2);

  //qDebug()<<n1<<":"<<n2;
  edges.append(tmp_edge);
  return tmp_edge;

}

void GVGraph::layout(QString layoutAlgo)
{

  agsafeset(graph, "dpi", "96,0","");
  agnodeattr(graph, "fixedsize","true");
  agnodeattr(graph, "width",(char *)QString::number(EntityIcon::totalWidth/96.0).toStdString().c_str());
  agnodeattr(graph, "height",(char *)QString::number(EntityIcon::totalWidth/96.0).toStdString().c_str());
  agnodeattr(graph, "shape","square");
  agnodeattr(graph, "label","");
  agnodeattr(graph, "regular", "true");
  agsafeset(graph, "pad", "0,2","");

  agsafeset(graph, "overlap", "prism","");
  agsafeset(graph, "splines", "true","");
  agsafeset(graph, "nodesep", "0,4","");

  gvLayout (gvc, graph, layoutAlgo.toStdString().c_str());
  qreal swidth= nodes.begin().key()->scene()->sceneRect().width()/2;
  qreal sheight= nodes.begin().key()->scene()->sceneRect().height()/2;

  for(QMap<EntityIcon*, Agnode_t*>::const_iterator it=nodes.begin(); it!=nodes.end();++it)
  {
      Agnode_t* node=it.value();
      qreal x=(((node->u.coord.x))*(96.0/72.0))-(150/2);
      qreal y=((((graph->u.bb.UR.y) - node->u.coord.y))*(96.0/72.0)) -(150/2.0) ;
      it.key()->setPos(swidth+x,sheight+y);
  }

}


