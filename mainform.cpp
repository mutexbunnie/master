#include "mainform.h"
#include "ui_mainform.h"
#include <QPainter>
#include "entitytypebutton.h"
#define PI 3.14159265
#include <QDebug>



MainForm::MainForm(ProjectStore* projectStore, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->actionSelection->setChecked(true);
    scrollArea = new QScrollArea(0);
    activeDialog= new ActiveDialog(0);
    scrollArea->setWidget(activeDialog);

    ui->tabWidget->addTab(scrollArea ,"Sheet 1");

    scrollArea2 = new QScrollArea(0);
    activeDialog2= new ActiveDialog(0);

    scrollArea2->setWidget(activeDialog2);
    ui->tabWidget->addTab(scrollArea2 ,"Sheet 2");

    connect(ui->actionSelection, SIGNAL(toggled(bool)), this, SLOT(toggleSelectionState(bool)));
    this->entityTypeButtons = new QVector<EntityTypeButton*>();


    ui->entityBoxLayout->setAlignment(Qt::AlignTop);


    for (int i=0;i<projectStore->entityTypes->size() ;i++)
    {
        qDebug()  << projectStore->entityTypes->at(i)->name;

      EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent,(*(projectStore->entityTypes))[i]);
      ui->entityBoxLayout->addWidget(tmp_entityButton);
      connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
      this->entityTypeButtons->append(tmp_entityButton);

      QString location= (*(projectStore->entityTypes))[i]->datalocation;


      QVector<QVector<QVariant>*>*  tmp_fields=((*(projectStore->entityTypes))[i])->datasource->getFields(location," 1=1 ");


      for (int k=0; k<tmp_fields->size() ;k++)
          {
           Entity* tmp_entity = new Entity(activeDialog,(*(projectStore->entityTypes))[i]);

          for (int j=0; j<(*tmp_fields)[k]->size();j++)
             {
                   qDebug() <<((*(*tmp_fields)[k])[j]).toString();

                   //if ((*(*(projectStore->entityTypes))[i]->fieldMap->fieldDescriptions)[j]->fieldType==0)

                   //tmp_entity->ad
             }
              activeDialog->addEntity(tmp_entity,0,0);
          }
    }

    QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->entityBoxLayout->addItem(verticalSpacer);


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
                   activeDialog->newEntityType=(*entityTypeButtons)[i]->entityType;
                   break;
                }
            }
    }
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
    selectionState=selection;
    activeDialog->selectionActive=selectionState;
    activeDialog2->selectionActive=selectionState;
 qDebug()<<"MainForm::toggleSelectionState"<<selectionState;

}


MainForm::~MainForm()
{
   // delete ui;
}

void MainForm::on_pushButton_toggled(bool checked)
{
    if (checked)  ui->entityBox->show();
    else ui->entityBox->hide();


}
