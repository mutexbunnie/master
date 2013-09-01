#ifndef GRAPHICSHEET_H
#define GRAPHICSHEET_H

#include "graphicsscene.h"
#include "graphicsview.h"
#include <QToolBar>
#include <QAction>
#include <QHBoxLayout>
#include <QApplication>
#include <QObject>
#include <QTabWidget>

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
    QFrame* dataFrame;
    QFrame* mainFrame;
    QTabWidget* tableTabs;

    QHBoxLayout* dataFrameLayout;
    QVBoxLayout* mainFrameLayout;
    QToolBar* toolbar;

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


    ProjectSheet* projectSheet;

    void addEntityToolButtons(QToolBar* ui_toolbar);
   private:
    void constructToolbar();
};

#endif // GRAPHICSHEET_H
