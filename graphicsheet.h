#ifndef GRAPHICSHEET_H
#define GRAPHICSHEET_H

#include "graphicsscene.h"
#include "graphicsview.h"
#include <QToolBar>
#include <QAction>
#include <QVBoxLayout>
#include <QApplication>

class ProjectSheet;

class GraphicSheet
{

public:
    GraphicSheet(ProjectSheet* projectSheet);
    GraphicsView* graphicsView;
    GraphicsScene* scene;
    QFrame* frame;
    QVBoxLayout* layout;
    QToolBar* toolbar;
    QAction *actionLink;
    QAction *actionSelection;
    QAction *actionAutoLayout;
    QAction *actionSave;
    QAction *actionAutoLink;
    QAction *actionRemove;
    QAction *actionAutoZoom;
    QFrame* frame2;
    QVBoxLayout* layout2;
    ProjectSheet* projectSheet;

};

#endif // GRAPHICSHEET_H
