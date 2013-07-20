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
        //ui->toolBar_2->setVisible(false);
        ui->entityBox_2->hide();

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
   /* if (selection)
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
    }*/
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
            QToolBar* toolbar = new  QToolBar(frame);
            QAction *actionLink;
            QAction *actionSelection;
            QAction *actionAutoLayout;
            QAction *actionSave;
            QAction *actionAutoLink;
            QAction *actionRemove;
            QAction *actionAutoZoom;
            actionSelection = new QAction(frame);
            actionSelection->setObjectName(QString::fromUtf8("actionSelection"));
            actionSelection->setCheckable(true);
            QIcon icon;
            icon.addFile(QString::fromUtf8(":/icons/mouse_pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionSelection->setIcon(icon);

            actionLink = new QAction(frame);
            actionLink->setObjectName(QString::fromUtf8("actionLink"));
            actionLink->setCheckable(true);
            QIcon icon1;
            icon1.addFile(QString::fromUtf8(":/icons/insert-link-2.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionLink->setIcon(icon1);

            actionAutoLayout = new QAction(frame);
            actionAutoLayout->setObjectName(QString::fromUtf8("actionAutoLayout"));
            actionAutoLayout->setCheckable(true);
            QIcon icon2;
            icon2.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionAutoLayout->setIcon(icon2);
            actionSave = new QAction(frame);
            actionSave->setObjectName(QString::fromUtf8("actionSave"));
            QIcon icon3;
            icon3.addFile(QString::fromUtf8(":/icons/document-save-as-4.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionSave->setIcon(icon3);
            actionAutoLink = new QAction(frame);
            actionAutoLink->setObjectName(QString::fromUtf8("actionAutoLink"));
            QIcon icon4;
            icon4.addFile(QString::fromUtf8(":/icons/insert-link.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionAutoLink->setIcon(icon4);
            actionRemove = new QAction(frame);
            actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
            QIcon icon5;
            icon5.addFile(QString::fromUtf8(":/icons/osa_lightning.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionRemove->setIcon(icon5);
            actionAutoZoom = new QAction(frame);
            actionAutoZoom->setObjectName(QString::fromUtf8("actionAutoZoom"));
            QIcon icon6;
            icon6.addFile(QString::fromUtf8(":/icons/star.png"), QSize(), QIcon::Normal, QIcon::Off);
            actionAutoZoom->setIcon(icon6);

            actionSelection->setText(QApplication::translate("MainForm", "Selection", 0, QApplication::UnicodeUTF8));
            actionLink->setText(QApplication::translate("MainForm", "Link", 0, QApplication::UnicodeUTF8));
            actionAutoLayout->setText(QApplication::translate("MainForm", "AutoLayout", 0, QApplication::UnicodeUTF8));
            actionSave->setText(QApplication::translate("MainForm", "Save", 0, QApplication::UnicodeUTF8));
            actionAutoLink->setText(QApplication::translate("MainForm", "AutoLink", 0, QApplication::UnicodeUTF8));
            actionRemove->setText(QApplication::translate("MainForm", "Remove", 0, QApplication::UnicodeUTF8));
            actionAutoZoom->setText(QApplication::translate("MainForm", "AutoZoom", 0, QApplication::UnicodeUTF8));

            toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

            toolbar->addAction(actionSelection);
            toolbar->addAction(actionLink);
            toolbar->addAction(actionAutoLayout);
            toolbar->addAction(actionSave);
            toolbar->addAction(actionAutoLink);
            toolbar->addAction(actionRemove);
            toolbar->addAction(actionAutoZoom);

            layout->addWidget(toolbar);
            toolbar->setMovable(true);
            toolbar->setFloatable(true);
            layout->addWidget(graphicsView);
            QFrame* frame2 = new QFrame();
            QVBoxLayout* layout2 = new QVBoxLayout();
            frame2->setLayout(layout2);



             scene= new  GraphicsScene(0);
            scene->addSheetMap(((*(projectStore->projectSheets))[i]->projectSheet));
            for (int i=0;i<projectStore->entityTypes->size() ;i++)
            {
              QAction* tmp_Action =new QAction(this);


              tmp_Action->setCheckable(true);
              tmp_Action->setText(((*(projectStore->entityTypes))[i])->name);
              tmp_Action->setIcon(((*(projectStore->entityTypes))[i])->normal);
              toolbar->addAction(tmp_Action);


             // EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent_2,(*(projectStore->entityTypes))[i]);
              //ui->entityBoxLayout_2->addWidget(tmp_entityButton);
              //connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
              //this->entityTypeButtons->append(tmp_entityButton);

              QTableView* tableView = new QTableView();
              layout2->addWidget(tableView);
              tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
              scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));
            }
             scene->addSheetLink(((*(projectStore->projectSheets))[i]->projectLink));
             graphicsView->setScene(scene);
             //scene->layoutItems();
             //scene->autoZoom();

             ui->tabWidget_2->addTab(frame,(*(projectStore->projectSheets))[i]->sheetname);
             projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);
             ui->tabWidget_2->addTab(frame2,"Tables 1");
             projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);

            QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            ui->entityBoxLayout_2->addItem(verticalSpacer1);
            graphicsView->setCenter(QPointF((graphicsView->sceneRect().width()/2)+512,(graphicsView->sceneRect().height()/2)+512));



            toolbar->addAction(actionSave);
            toolbar->addAction(actionAutoLink);

            connect(actionSelection, SIGNAL(toggled(bool)), graphicsView, SLOT(setSelectMode(bool)));
            connect(actionLink, SIGNAL(toggled(bool)), scene, SLOT(setLinkMode(bool)));
            connect(actionAutoLayout, SIGNAL(toggled(bool)), scene, SLOT(setAutoLayout(bool)));


            connect(actionRemove,SIGNAL(triggered()), scene, SLOT(removeSelected()));
            connect(actionAutoZoom,SIGNAL(triggered()), scene, SLOT(autoZoom()));
            //ui->actionSelection->setChecked(true);
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


}

void MainForm::on_pushButton_2_clicked()
{

}

void MainForm::on_actionEntities_triggered()
{

}

void MainForm::on_actionEntities_triggered(bool checked)
{
    //if (checked)  ui->entityBox_2->show();
    //else ui->entityBox_2->hide();

    ui->toolBar_2->setVisible(!ui->toolBar_2->isVisible());
}

void MainForm::on_actionAutoZoom_triggered()
{

}
