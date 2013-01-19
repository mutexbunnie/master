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
  /*more than on scene*/
   for (int i=0; i<projectStore->projectSheets->size();i++)
   {
        GraphicsView* graphicsView = new GraphicsView();
        graphicsView->setFocus();

        scene= new  GraphicsScene(0);
        scene->setSceneRect(0,0,16777215,16777215);
        graphicsView->setCenter(QPointF(0.0,0.0));
    /*   //Populate the scene
                for(int x = 0; x < 4000; x = x + 25)
                {
                for(int y = 0; y < 4000; y = y + 25) {
                   if(x % 100 == 0 && y % 100 == 0) {
                       scene->addRect(x, y, 2, 2);

                       QString pointString;
                       QTextStream stream(&pointString);
                       stream << "(" << x << "," << y << ")";
                       QGraphicsTextItem* item = scene->addText(pointString);
                       item->setPos(x, y);
                   } else {
                       scene->addRect(x, y, 1, 1);
                   }
               }
           }*/
       graphicsView->setScene(scene);
       graphicsView->scale(1.0,1.0);
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

       scene->addSheetMap(((*(projectStore->projectSheets))[i]->projectSheet));

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

      scene->addSheetLink(((*(projectStore->projectSheets))[i]->projectLink));
      ui->tabWidget_2->addTab(frame,"Sheet 1");
     // projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);
      ui->tabWidget_2->addTab(frame2,"Tables 1");
      //projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);

      QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
      ui->entityBoxLayout_2->addItem(verticalSpacer1);
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

void MainForm::on_actionAutoLink_triggered()
{
    QSqlDatabase dbConnection =  QSqlDatabase::addDatabase("QMYSQL","testy");
    dbConnection.setHostName("localhost");
    dbConnection.setDatabaseName("test");
    dbConnection.setUserName("root");
    dbConnection.setPassword("root");
    bool ok = dbConnection.open();
  //  QSqlQuery joinQuery("select distinctrow FirstName as UID1,ip as UID2 from Persons join log on Persons.FirstName=log.user",dbConnection);
    //traceroute//
    //traceroute www.google.com | awk {'print $2","$3'} |tr -d "()" >/tmp/trace
    //truncate traceroute; load data local infile '/tmp/trace' into table traceroute fields terminated by ',' enclosed by '"' (hostname,ip) ;

   // QSqlQuery joinQuery("select traceroute1.ip as 'UID1',traceroute2.ip as 'UID2' from traceroute as traceroute1 join traceroute as traceroute2 on traceroute1.id+1=traceroute2.id",dbConnection);
 //QSqlQuery joinQuery("select traceroute1.ip as 'UID1',traceroute2.ip as 'UID2' from traceroute as traceroute1 join traceroute as traceroute2 on traceroute1.id+1=traceroute2.id",dbConnection);
 //QSqlQuery joinQuery("select distinctrow ip4 as UID1 ,port as UID2 from hosts  join ports on hosts.hid=ports.hid; ",dbConnection);

 // QSqlQuery joinQuery("select distinctrow host  as UID1 ,  user as UID2 from users",dbConnection);
   QSqlQuery joinQuery("select host1 as UID1,host2 as UID2 from combined where amount>95 ",dbConnection);

    qDebug()  << "Loading";



    while (joinQuery.next())
    {

       QString uid1 = joinQuery.value(0).toString();
       QString uid2 = joinQuery.value(1).toString();
//       qDebug()<<uid1<<uid2;

       scene->createEdge("host",uid1,"host",uid2);
       scene->createEdge("host",uid2,"host",uid1);
    }


    /*QSqlQuery joinQuery2("select distinctrow host  as UID1 ,  app as UID2 from app",dbConnection);

    qDebug()  << "Loading";



    while (joinQuery2.next())
    {

       QString uid1 = joinQuery2.value(0).toString();
       QString uid2 = joinQuery2.value(1).toString();
//       qDebug()<<uid1<<uid2;

       scene->createEdge("host",uid1,"app",uid2);
       scene->createEdge("app",uid2,"host",uid1);
    }
*/

   scene->hideOrphan();



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
