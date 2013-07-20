#include "GVGraph.h"
#include <QDebug>
#include "QGraphicsScene"
GVGraph::GVGraph()
{
    gvc = gvContext();
    graph= agopen("Graph", AGDIGRAPHSTRICT);
    //gvc=((*entityIcons)[i])->getUidValue();

}

Agnode_t* GVGraph::addNode(EntityIcon* node)
{
   Agnode_t* tmp_Node = agnode(graph, (char*)node->getUidValue().toStdString().c_str());
   nodes.insert(node,tmp_Node);
  // qDebug()<<(char*) UID.toStdString().c_str();
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
  qDebug()<<"Called";
  agsafeset(graph, "dpi", "96,0","");
  agnodeattr(graph, "fixedsize","true");
  agnodeattr(graph, "width","1.56");
  agnodeattr(graph, "height","1.56");
  agnodeattr(graph, "shape","square");
  agnodeattr(graph, "label","");
  agnodeattr(graph, "regular", "true");
  agsafeset(graph, "pad", "0,2","");

  agsafeset(graph, "overlap", "prism","");
  agsafeset(graph, "splines", "true","");
  agsafeset(graph, "nodesep", "0,4","");

  //qDebug()<< agget(graph, "dpi");

   //gvLayout (gvc, graph, "dot");
 // gvLayout (gvc, graph, "neato");
  gvLayout (gvc, graph, layoutAlgo.toStdString().c_str());

  qreal swidth= nodes.begin().key()->scene()->sceneRect().width()/2;
  qreal sheight= nodes.begin().key()->scene()->sceneRect().height()/2;

  for(QMap<EntityIcon*, Agnode_t*>::const_iterator it=nodes.begin(); it!=nodes.end();++it)
  {
      Agnode_t* node=it.value();
      qDebug()<<node->u.width<<":"<<node->u.height;

      qreal x=(((node->u.coord.x))*(96.0/72.0))-(150/2);
      qreal y=((((graph->u.bb.UR.y) - node->u.coord.y))*(96.0/72.0)) -(150/2.0) ;
      it.key()->setPos(swidth+x,sheight+y);
      //qDebug()<<"K"<<x<<":"<<y;
      //qDebug()<<graph->u.bb.UR.y *(96.0/72.0)<<":"<<node->u.coord.y*(96.0/72.0);
  }
 //gvRenderFilename (gvc, graph, "png", "out.png");

  //object.name=node->name;

  //Fetch the X coordinate, apply the DPI conversion rate (actual DPI / 72, used by dot)
  //qreal x=node->u.coord.x*(dpi/DotDefaultDPI);
  //Translate the Y coordinate from bottom-left to top-left corner
  //qreal y=(_graph->u.bb.UR.y - node->u.coord.y)*(dpi/DotDefaultDPI);
  //object.centerPos=QPoint(x, y);
}

GVGraph::~GVGraph()
{
    gvFreeLayout(gvc, graph);
    agclose(graph);
    gvFreeContext(gvc);
}

