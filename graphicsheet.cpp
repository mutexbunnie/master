#include "graphicsheet.h"
#include "projectsheet.h"
#include "projectstore.h"
#include <QObject>
GraphicSheet::GraphicSheet(ProjectSheet *projectSheet)
{
                this->projectSheet=projectSheet;
                frame = new QFrame();
                layout = new QVBoxLayout();
                frame->setLayout(layout);
                toolbar = new  QToolBar(frame);

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

                actionDotLayout = new QAction(frame);
                actionDotLayout->setObjectName(QString::fromUtf8("actionDotLayout"));
                //actionDotLayout->setCheckable(true);
                QIcon icon2;
                icon2.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
                actionDotLayout->setIcon(icon2);
                actionDotLayout->setText(QApplication::translate("MainForm", "DotLayout", 0, QApplication::UnicodeUTF8));
                QObject::connect(actionDotLayout, SIGNAL(triggered()), this, SLOT(dotLayout()));


                actionNeatoLayout = new QAction(frame);
                actionNeatoLayout->setObjectName(QString::fromUtf8("actionNeatoLayout"));
              //  actionNeatoLayout->setCheckable(true);
                QIcon icon7;
                icon7.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
                actionNeatoLayout->setIcon(icon2);
                actionNeatoLayout->setText(QApplication::translate("MainForm", "NeatoLayout", 0, QApplication::UnicodeUTF8));
                QObject::connect(actionNeatoLayout, SIGNAL(triggered()), this, SLOT(neatoLayout()));

                actionfdpLayout = new QAction(frame);
                actionfdpLayout->setObjectName(QString::fromUtf8("actionfdpLayout"));
               // actionfdpLayout->setCheckable(true);
                QIcon icon8;
                icon8.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
                actionfdpLayout->setIcon(icon2);
                actionfdpLayout->setText(QApplication::translate("MainForm", "FDPLayout", 0, QApplication::UnicodeUTF8));
                QObject::connect(actionfdpLayout, SIGNAL(triggered()), this, SLOT(fdpLayout()));


                actionsfdpLayout = new QAction(frame);
                actionsfdpLayout->setObjectName(QString::fromUtf8("actionsfdpLayout"));
                //actionsfdpLayout->setCheckable(true);
                QIcon icon9;
                icon9.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
                actionsfdpLayout->setIcon(icon2);
                actionsfdpLayout->setText(QApplication::translate("MainForm", "SFDPLayout", 0, QApplication::UnicodeUTF8));
                QObject::connect(actionsfdpLayout, SIGNAL(triggered()), this, SLOT(sfdpLayout()));

                actionelasticLayout = new QAction(frame);
                actionelasticLayout->setObjectName(QString::fromUtf8("actionelasticLayout"));
                //actionelasticLayout->setCheckable(true);
                QIcon icon10;
                icon10.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
                actionelasticLayout->setIcon(icon2);
                actionelasticLayout->setText(QApplication::translate("MainForm", "ElasticLayout", 0, QApplication::UnicodeUTF8));
                QObject::connect(actionelasticLayout, SIGNAL(triggered()), this, SLOT(elasticLayout()));

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

                actionSave->setText(QApplication::translate("MainForm", "Save", 0, QApplication::UnicodeUTF8));
                actionAutoLink->setText(QApplication::translate("MainForm", "AutoLink", 0, QApplication::UnicodeUTF8));
                actionRemove->setText(QApplication::translate("MainForm", "Remove", 0, QApplication::UnicodeUTF8));
                actionAutoZoom->setText(QApplication::translate("MainForm", "AutoZoom", 0, QApplication::UnicodeUTF8));

                toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
                toolbar->addAction(actionSelection);
                toolbar->addAction(actionLink);

                toolbar->addAction(actionSave);
                toolbar->addAction(actionAutoLink);
                toolbar->addAction(actionRemove);
                toolbar->addAction(actionAutoZoom);

                toolbar->addAction(actionDotLayout);
                toolbar->addAction(actionNeatoLayout);
                toolbar->addAction(actionfdpLayout);
                toolbar->addAction(actionsfdpLayout);
                toolbar->addAction(actionelasticLayout);


                toolbar->setMovable(true);
                toolbar->setFloatable(true);
                layout->addWidget(toolbar);

                scene= new  GraphicsScene(0);
               scene->addSheetMap(projectSheet->projectSheet);
                scene->addSheetLink(projectSheet->projectLink);



                ProjectStore * projectStore=projectSheet->projectStore;

                for (int i=0;i<projectStore->entityTypes->size() ;i++)
                {
                  QAction* tmp_Action =new QAction(frame);
                  tmp_Action->setCheckable(true);
                  tmp_Action->setText(((*(projectStore->entityTypes))[i])->name);
                  tmp_Action->setIcon(((*(projectStore->entityTypes))[i])->normal);
                  toolbar->addAction(tmp_Action);

                 // EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent_2,(*(projectStore->entityTypes))[i]);
                  //ui->entityBoxLayout_2->addWidget(tmp_entityButton);
                  //connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
                  //this->entityTypeButtons->append(tmp_entityButton);

                  //QTableView* tableView = new QTableView();
                  //layout2->addWidget(tableView);
                  //tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
                  scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));
                }

                graphicsView = new GraphicsView();
                graphicsView->setFocus();
                layout->addWidget(graphicsView);
                graphicsView->setScene(scene);
                graphicsView->setCenter(QPointF((graphicsView->sceneRect().width()/2)+512,(graphicsView->sceneRect().height()/2)+512));

                QObject::connect(actionSelection, SIGNAL(toggled(bool)), graphicsView, SLOT(setSelectMode(bool)));
                QObject::connect(actionLink, SIGNAL(toggled(bool)), scene, SLOT(setLinkMode(bool)));


                QObject::connect(actionRemove,SIGNAL(triggered()), scene, SLOT(removeSelected()));
                QObject::connect(actionAutoZoom,SIGNAL(triggered()), scene, SLOT(autoZoom()));
                QObject::connect(actionAutoLink,SIGNAL(triggered()), this, SLOT(autoLink()));


              /* QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
                //ui->entityBoxLayout_2->addItem(verticalSpacer1);/*
                actionSelection->setChecked(true);*/
                //scene->layoutItems();
                //scene->autoZoom();
                //*QFrame* frame2 = new QFrame();
                //QVBoxLayout* layout2 = new QVBoxLayout();
                //frame2->setLayout(layout2);*/
                // this->entityTypeButtons = new QVector<EntityTypeButton*>();
                //ui->entityBoxLayout_2->setAlignment(Qt::AlignTop);
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

}

void GraphicSheet::autoLink()
{

    if (projectSheet->projectStore)
    {


       for(int i=0; i< projectSheet->projectStore->autoLinks->size();i++)
        {
             scene->addJoin(projectSheet->projectStore->autoLinks->at(i)->entityType1,
                            projectSheet->projectStore->autoLinks->at(i)->entityType2,
                            projectSheet->projectStore->autoLinks->at(i)->getModel());
        }
        scene->hideOrphan();
    }
   // scene->hideOrphan();
}


