#include "graphicsheet.h"

GraphicSheet::GraphicSheet()
{
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


                toolbar->setMovable(true);
                toolbar->setFloatable(true);
                layout->addWidget(toolbar);

                scene= new  GraphicsScene(0);
               //* scene->addSheetMap(((*(projectStore->projectSheets))[i]->projectSheet));
                /*scene->addSheetLink(((*(projectStore->projectSheets))[i]->projectLink));*/

              /*  for (int i=0;i<projectStore->entityTypes->size() ;i++)
                {
                  /*QAction* tmp_Action =new QAction(this);


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
                 //scene->layoutItems();
                 //scene->autoZoom();

                //*/QFrame* frame2 = new QFrame();
                //QVBoxLayout* layout2 = new QVBoxLayout();
                //frame2->setLayout(layout2);*/

}
