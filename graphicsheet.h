#ifndef GRAPHICSHEET_H
#define GRAPHICSHEET_H


#include <QObject>
#include "graphicsscene.h"
#include "graphicsview.h"
#include <QTableView>
#include <QSplitter>
#include <QHBoxLayout>
#include <QTabWidget>
#include "scenetoolbar.h"

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
//TODO::SHOULD be private
    QFrame* mainFrame;

private:
    GraphicsView* graphicsView;
    GraphicsScene* scene;
    QFrame* dataFrame;
    QTabWidget* tableTabs;
    QHBoxLayout* dataFrameLayout;
    QVBoxLayout* mainFrameLayout;
    ProjectSheet* projectSheet;
};

#endif // GRAPHICSHEET_H
