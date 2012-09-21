#include "mainform.h"
#include "ui_mainform.h"
#include <QPainter>
#include "entitytypebutton.h"
#define PI 3.14159265
#include <QDebug>



MainForm::MainForm(QVector<EntityType*>* entityTypes, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
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


    for (int i=0;i<entityTypes->size() ;i++)
    {
      EntityTypeButton* tmp_entity =new EntityTypeButton(ui->entityBoxContent,(*entityTypes)[i]);
      ui->entityBoxLayout->addWidget(tmp_entity);
      connect(tmp_entity , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
      this->entityTypeButtons->append(tmp_entity);
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
