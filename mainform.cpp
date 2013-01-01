#include "mainform.h"
#include "ui_mainform.h"
#include "entitytypebutton.h"
#include "graphicsview.h"
#include <mysqldatasource.h>
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

      //  terminal->setMinimumHeight(0);
      //  terminal->setMaximumHeight(200);

        ui->tabWidget->addTab(terminal1,"Session 1");
        ui->tabWidget->addTab(terminal2,"Session 2");


        //ui->verticalLayout_5->addWidget();
       // ui->frame->layout()->addWidget( m_part->widget());


}

void MainForm::toggleEntity(bool selection)
{
    /*if (selection)
    {
            if (selectionState)
            {
              ui->actionSelection->setChecked(false);
            }


            for (int i=0; i<entityTypeButtons->size(); i++)
            {
                if ((*entityTypeButtons)[i]->isChecked())
                {
                   activeDialog->newEntityType=(*entityTypeButtons)[i]->entityType;
                   break;
                }
            }
    }*/
}

void MainForm::toggleSelectionState(bool selection)
{
    if (selection)
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
   // selectionState=selection;
   // activeDialog->selectionActive=selectionState;
    //activeDialog2->selectionActive=selectionState;
 qDebug()<<"MainForm::toggleSelectionState"<<selectionState;

}



MainForm::~MainForm()
{
   // delete ui;
}




void MainForm::on_actionOpen_Project_triggered()
{
   QString filepath=QFileDialog::getOpenFileName(this, "Open Project File","","Files (*.xml)");
   projectStore= new ProjectStore();
   projectStore->loadProject(filepath);

   ui->actionSelection->setChecked(true);

   this->entityTypeButtons = new QVector<EntityTypeButton*>();
   ui->entityBoxLayout_2->setAlignment(Qt::AlignTop);

   //fix multiple sheets, mutliple views?

   QGraphicsView* graphicsView = new GraphicsView();
   graphicsView->setFocus();
   graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
   graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
   graphicsView -> setMinimumSize(400, 400);
   scene= new  GraphicsScene(0);
   scene->setSceneRect(0,0,1024,1024);
   graphicsView->setScene(scene);

   connect(ui->actionLink, SIGNAL(toggled(bool)), scene, SLOT(setLinkMode(bool)));
   connect(ui->actionAutoLayout, SIGNAL(toggled(bool)), scene, SLOT(setAutoLayout(bool)));


   QFrame* frame = new QFrame();
   QVBoxLayout* layout = new QVBoxLayout();
   frame->setLayout(layout);
   layout->addWidget(graphicsView);


   QFrame* frame2 = new QFrame();
   QVBoxLayout* layout2 = new QVBoxLayout();
   frame2->setLayout(layout2);



     // QTabWidget* entityTables=new QTabWidget();

    //  QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    //  layout->addItem(verticalSpacer);
    //  layout->addWidget(entityTables);

      scene->addSheetMap(projectStore->projectSheet);


      for (int i=0;i<projectStore->entityTypes->size() ;i++)
      {
          EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent_2,(*(projectStore->entityTypes))[i]);
          ui->entityBoxLayout_2->addWidget(tmp_entityButton);
          connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
          this->entityTypeButtons->append(tmp_entityButton);

          QTableView* tableView = new QTableView();
          //entityTables->addTab(tableView, projectStore->entityTypes->at(i)->name);
          layout2->addWidget(tableView);
          tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
          scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));

      }

      scene->addSheetLink(projectStore->projectLink);

       ui->tabWidget_2->addTab(frame,"Sheet 1");
       ui->tabWidget_2->addTab(frame2,"Tables 1");

      QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
      ui->entityBoxLayout_2->addItem(verticalSpacer1);
}


void MainForm::on_actionSave_triggered()
{
    qDebug()<<"Start save";
    scene->save();
    projectStore->projectSheet=scene->getSheetMap();
    projectStore->saveScene();
    qDebug()<<"Stop save";

}

void MainForm::on_actionAutoLink_triggered()
{
    QSqlDatabase dbConnection =  QSqlDatabase::addDatabase("QMYSQL","testy");
    dbConnection.setHostName("localhost");
    dbConnection.setDatabaseName("test");
    dbConnection.setUserName("root");
    dbConnection.setPassword("root");
    bool ok = dbConnection.open();
    QSqlQuery joinQuery("select distinctrow FirstName as UID1,ip as UID2 from Persons join log on Persons.FirstName=log.user",dbConnection);
    qDebug()  << "Loading";



    while (joinQuery.next())
    {

       QString uid1 = joinQuery.value(0).toString();
       QString uid2 = joinQuery.value(1).toString();
       scene->createEdge("User",uid1,"ip",uid2);
       scene->createEdge("ip",uid2,"User",uid1);
    }

  scene->hideOrphan();



}

void MainForm::on_pushButton_2_toggled(bool checked)
{
    if (checked)  ui->entityBox_2->show();
    else ui->entityBox_2->hide();

}
