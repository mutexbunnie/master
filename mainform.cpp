#include "mainform.h"
#include "ui_mainform.h"
#include "entitytypebutton.h"
#include "graphicsview.h"
#include <QTableView>
#include <QDebug>
#include <QFileDialog>
#include "kservice.h"
#include "kparts/part.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
        ui->setupUi(this);
        KService::Ptr service = KService::serviceByDesktopPath("konsolepart.desktop");
        KParts::ReadOnlyPart *m_part = service->createInstance<KParts::ReadOnlyPart>(0);
        QWidget* terminal1=m_part->widget();
        KParts::ReadOnlyPart *m_part2 = service->createInstance<KParts::ReadOnlyPart>(0);
        QWidget* terminal2=m_part2->widget();
        ui->tabWidget->addTab(terminal1,"Session 1");
        ui->tabWidget->addTab(terminal2,"Session 2");
        entityTypeButtons=0;
        projectStores=new QVector<ProjectStore*>();
}

void MainForm::toggleEntity(bool selection)
{
    if (selection)
    {
            if (selectionState)
            {
              ui->actionSelection->setChecked(false);
            }

            for (int i=0; i<entityTypeButtons->size(); i++)
            {
                if ((*entityTypeButtons)[i]->isChecked())
                {
                   //activeDialog->newEntityType=(*entityTypeButtons)[i]->entityType;
                   break;
                }
            }
    }
}


MainForm::~MainForm()
{
   // delete ui;
}




void MainForm::on_actionOpen_Project_triggered()
{
    QString filepath=QFileDialog::getOpenFileName(this, "Open Project File","","Files (*.xml)");
    if (filepath !="")
    {
        ProjectStore* projectStore= new ProjectStore();
        projectStore->loadProject(filepath);
        projectStores->append(projectStore);

        ui->actionSelection->setChecked(true);
        this->entityTypeButtons = new QVector<EntityTypeButton*>();
        ui->entityBoxLayout_2->setAlignment(Qt::AlignTop);

/*fix just one scene*/
        for (int i=0; i<projectStore->projectSheets->size();i++)
        {
            GraphicsView* graphicsView = new GraphicsView();
            graphicsView->setFocus();

            QFrame* frame = new QFrame();
            QVBoxLayout* layout = new QVBoxLayout();
            frame->setLayout(layout);
            layout->addWidget(graphicsView);
            QFrame* frame2 = new QFrame();
            QVBoxLayout* layout2 = new QVBoxLayout();
            frame2->setLayout(layout2);

             scene= new  GraphicsScene(0);
            scene->addSheetMap(((*(projectStore->projectSheets))[i]->projectSheet));
            for (int i=0;i<projectStore->entityTypes->size() ;i++)
            {
              EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent_2,(*(projectStore->entityTypes))[i]);
              ui->entityBoxLayout_2->addWidget(tmp_entityButton);
              connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
              this->entityTypeButtons->append(tmp_entityButton);

              QTableView* tableView = new QTableView();
              layout2->addWidget(tableView);
              tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
              scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));
            }
             scene->addSheetLink(((*(projectStore->projectSheets))[i]->projectLink));
             graphicsView->setScene(scene);

             ui->tabWidget_2->addTab(frame,(*(projectStore->projectSheets))[i]->sheetname);
             projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);
             ui->tabWidget_2->addTab(frame2,"Tables 1");
             projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);

            QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            ui->entityBoxLayout_2->addItem(verticalSpacer1);
            graphicsView->setCenter(QPointF((graphicsView->sceneRect().width()/2)+512,(graphicsView->sceneRect().height()/2)+512));

            connect(ui->actionLink, SIGNAL(toggled(bool)), scene, SLOT(setLinkMode(bool)));
            connect(ui->actionAutoLayout, SIGNAL(toggled(bool)), scene, SLOT(setAutoLayout(bool)));
            connect(ui->actionSelection, SIGNAL(toggled(bool)), graphicsView, SLOT(setSelectMode(bool)));
        }
    }
}


void MainForm::on_actionSave_triggered()
{
   /* qDebug()<<"Start save";
    scene->save();
    projectStore->projectSheet=scene->getSheetMap();
    projectStore->saveScene();
    qDebug()<<"Stop save";*/

}


void MainForm::on_pushButton_2_toggled(bool checked)
{
    if (checked)  ui->entityBox_2->show();
    else ui->entityBox_2->hide();

}

void MainForm::on_tabWidget_2_currentChanged(int index)
{
    qDebug()<<index;
}

void MainForm::on_tabWidget_2_tabCloseRequested(int index)
{
    qDebug()<<index;

    ui->tabWidget_2->removeTab(index);
    projectSheetMap.remove(index);
}

void MainForm::on_actionSelection_toggled(bool selection)
{

    if (selection)
    {

        if (entityTypeButtons!=0)
        {
                for (int i=0; i<entityTypeButtons->size(); i++)
                {
                    (*entityTypeButtons)[i]->setAutoExclusive(false);
                }
                for (int i=0; i<entityTypeButtons->size(); i++)
                {
                    (*entityTypeButtons)[i]->setChecked(false);
                }

                for (int i=0; i<entityTypeButtons->size(); i++)
                {
                    (*entityTypeButtons)[i]->setAutoExclusive(true);
                }
        }
    }
     selectionState=selection;
}

void MainForm::on_actionLink_triggered()
{

}

void MainForm::on_actionAutoLink_triggered()
{
    qDebug()<<"void MainForm::on_actionLink_triggered()";
    ProjectStore* projectStore= projectSheetMap.value(ui->tabWidget_2->currentIndex());

    if (projectStore)
    {
        for(int i=0; i< projectStore->autoLinks->size();i++)
        {
             scene->addJoin(projectStore->autoLinks->at(i)->entityType1,projectStore->autoLinks->at(i)->entityType2,projectStore->autoLinks->at(i)->getModel());
        }
        scene->hideOrphan();
    }
    scene->hideOrphan();
}

void MainForm::on_actionRemove_triggered()
{
 scene->removeSelected();

}
