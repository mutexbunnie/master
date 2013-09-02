#include "graphicsheet.h"
//TODO:FIX STUPID FORWARD DECLARATIONS!!! Dont remove below unti you do :(
#include "projectsheet.h"
#include "projectstore.h"

GraphicSheet::GraphicSheet(ProjectSheet *projectSheet)
{
    this->projectSheet=projectSheet;
    mainFrame = new QFrame();
    dataFrame = new QFrame(mainFrame);
    dataFrameLayout = new QHBoxLayout(dataFrame);
    mainFrameLayout = new QVBoxLayout(mainFrame);
    tableTabs= new QTabWidget(dataFrame);

    scene= new  GraphicsScene(0);
    scene->addSheetMap(projectSheet->projectSheet);
    scene->addSheetLink(projectSheet->projectLink);
    ProjectStore * projectStore=projectSheet->projectStore;

    for (int i=0;i<projectStore->entityTypes->size() ;i++)
    {
        QTableView* tableView = new QTableView();
        tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
        tableTabs->addTab(tableView,(*(projectStore->entityTypes))[i]->name);

        scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));
    }
    graphicsView = new GraphicsView();
    graphicsView->setFocus();
    graphicsView->setScene(scene);
    graphicsView->setCenter(QPointF((graphicsView->sceneRect().width()/2)+512,(graphicsView->sceneRect().height()/2)+512));

    QSplitter* splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(graphicsView);
    splitter->addWidget(tableTabs);
    dataFrameLayout->addWidget(splitter);
    mainFrameLayout->addWidget(SceneToolbar::toolbar);
    mainFrameLayout->addWidget(dataFrame);
}


void GraphicSheet::dotLayout()
{
    scene->setAutoLayout("dot");
}

void GraphicSheet::neatoLayout()
{
    scene->setAutoLayout("neato");
}

void GraphicSheet::fdpLayout()
{
    scene->setAutoLayout("fdp");
}

void GraphicSheet::sfdpLayout()
{
    scene->setAutoLayout("sfdp");
}

void GraphicSheet::elasticLayout()
{
  scene->setAutoLayout("elastic");
}

void GraphicSheet::autoLink()
{
    if (projectSheet->projectStore)
    {
       for (int i=0; i< projectSheet->projectStore->autoLinks->size();i++)
        {
             scene->addJoin(projectSheet->projectStore->autoLinks->at(i)->entityType1,
                            projectSheet->projectStore->autoLinks->at(i)->entityType2,
                            projectSheet->projectStore->autoLinks->at(i)->getModel());
        }
        scene->hideOrphan();
    }
}


