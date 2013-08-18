#ifndef GRAPHICSHEET_H
#define GRAPHICSHEET_H

#include "graphicsscene.h"
#include "graphicsview.h"
#include <QToolBar>
#include <QAction>
#include <QVBoxLayout>
#include <QApplication>
#include <QObject>

class ProjectSheet;

class GraphicSheet: public QObject
{
    Q_OBJECT

public slots:
  void autoLink();

  void dotLayout();
  void neatoLayout();
  void fdpLayout();
  void sfdpLayout();
  void elasticLayout();


public:

    GraphicSheet(ProjectSheet* projectSheet);
    GraphicsView* graphicsView;
    GraphicsScene* scene;
    QFrame* frame;
    QVBoxLayout* layout;
    QToolBar* toolbar;
    QToolBar* toolbar2;
    QAction *actionLink;
    QAction *actionSelection;

    QAction *actionDotLayout;
    QAction *actionNeatoLayout;
    QAction *actionfdpLayout;
    QAction *actionsfdpLayout;
    QAction *actionelasticLayout;

  //  QAction *actionSave;
    QAction *actionAutoLink;
    QAction *actionRemove;
    QAction *actionAutoZoom;
    QFrame* frame2;
    QVBoxLayout* layout2;
    ProjectSheet* projectSheet;

    void addEntityToolButtons(QToolBar* ui_toolbar);
};

#endif // GRAPHICSHEET_H
