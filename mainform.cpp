#include "mainform.h"
#include "ui_mainform.h"
#include <QPainter>
#include "entitytypebutton.h"
#define PI 3.14159265
#include <QDebug>



MainForm::MainForm(QDialog *parent) : QDialog(parent), ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->selection->setChecked(true);
    scrollArea = new QScrollArea(0);
    activeDialog= new ActiveDialog(0);
    scrollArea->setWidget(activeDialog);

    ui->tabWidget->addTab(scrollArea ,"Sheet 1");

    scrollArea2 = new QScrollArea(0);
    activeDialog2= new ActiveDialog(0);

    scrollArea2->setWidget(activeDialog2);
    ui->tabWidget->addTab(scrollArea2 ,"Sheet 2");

    connect(ui->selection, SIGNAL(toggled(bool)), this, SLOT(toggleSelectionState(bool)));
    this->entities = new QVector<EntityTypeButton*>();

    EntityType* starEntityType =new EntityType(":/icons/star.png");

    EntityType* compEntityType =new EntityType(":/icons/Computer.png");

    ui->entityBoxLayout->setAlignment(Qt::AlignTop);



    for (int i=0;i<2 ;i++)
    {
      EntityTypeButton* tmp_entity =new EntityTypeButton(ui->entityBoxContent,starEntityType);
      ui->entityBoxLayout->addWidget(tmp_entity);
      connect(tmp_entity , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
      this->entities->append(tmp_entity);
    }

    for (int i=0;i<8 ;i++)
    {
      EntityTypeButton* tmp_entity =new EntityTypeButton(ui->entityBoxContent,compEntityType);
      ui->entityBoxLayout->addWidget(tmp_entity);
      connect(tmp_entity , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
      this->entities->append(tmp_entity);
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
              ui->selection->setChecked(false);
            }


            for (int i=0; i<entities->size(); i++)
            {
                if ((*entities)[i]->isChecked())
                {
                   activeDialog->newEntityType=(*entities)[i]->entityType;
                   break;
                }
            }
    }
}

void MainForm::toggleSelectionState(bool selection)
{



    if (selection)
    {

                for (int i=0; i<entities->size(); i++)
                {
                    (*entities)[i]->setAutoExclusive(false);
                }
                for (int i=0; i<entities->size(); i++)
                {
                    (*entities)[i]->setChecked(false);
                }

                for (int i=0; i<entities->size(); i++)
                {
                    (*entities)[i]->setAutoExclusive(true);
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
