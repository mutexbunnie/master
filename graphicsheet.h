#ifndef GRAPHICSHEET_H
#define GRAPHICSHEET_H

#include "graphicsscene.h"
#include "graphicsview.h"
#include <QToolBar>
#include <QAction>
#include <QVBoxLayout>
#include <QApplication>
#include "projectstore.h"
#include "projectstore.h"

class GraphicSheet
{
public:
    GraphicSheet();
    GraphicsView* graphicsView;
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
    GraphicsScene* scene;
};

#endif // GRAPHICSHEET_H
