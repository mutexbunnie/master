#include "mainform.h"
#include "ui_mainform.h"
#include "entitytypebutton.h"
#include "graphicsview.h"
#include <mysqldatasource.h>
#include <QTableView>
#include <QDebug>
#include <QFileDialog>

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
        ui->setupUi(this);


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

void MainForm::on_pushButton_toggled(bool checked)
{
    if (checked)  ui->entityBox->show();
    else ui->entityBox->hide();
}

MainForm::~MainForm()
{
   // delete ui;
}


void MainForm::on_actionLink_triggered(bool checked)
{

}

void MainForm::on_actionOpen_Project_triggered()
{
   QString filepath=QFileDialog::getOpenFileName(this, "Open Project File","","Files (*.xml)");
   projectStore= new ProjectStore();
   projectStore->loadProject(filepath);

   ui->actionSelection->setChecked(true);

   this->entityTypeButtons = new QVector<EntityTypeButton*>();
   ui->entityBoxLayout->setAlignment(Qt::AlignTop);

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


      for (int i=0;i<projectStore->entityTypes->size() ;i++)
      {
          EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent,(*(projectStore->entityTypes))[i]);
          ui->entityBoxLayout->addWidget(tmp_entityButton);
          connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
          this->entityTypeButtons->append(tmp_entityButton);

          QTableView* tableView = new QTableView();
          //entityTables->addTab(tableView, projectStore->entityTypes->at(i)->name);
          layout2->addWidget(tableView);
          tableView->setModel(((*(projectStore->entityTypes))[i])->entitySource->getModel());
          scene->addModel(((*(projectStore->entityTypes))[i])->entitySource->getModel(),projectStore->entityTypes->at(i));
      }

       ui->tabWidget->addTab(frame,"Sheet 1");
       ui->tabWidget->addTab(frame2,"Tables 1");

      QSpacerItem* verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
      ui->entityBoxLayout->addItem(verticalSpacer1);
}

