#include "mainform.h"
#include "ui_mainform.h"
#include <QPainter>
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
    QIcon q(":/icons/star.png");


    connect(ui->selection, SIGNAL(toggled(bool)), this, SLOT(toggleSelectionState(bool)));
    this->entities = new QVector<QPushButton*>();

    for (int i=0;i<2 ;i++)
    {

    QPushButton* tmp_entity =new QPushButton(ui->entityBoxContent);
    ui->verticalLayout->addWidget(tmp_entity);
    tmp_entity->setMaximumSize(50,50);
    tmp_entity->setMinimumSize(50,50);
    QSize s(50,50);
    tmp_entity->setIconSize(s);
    tmp_entity->setCheckable(true);
    tmp_entity->setIcon(q);
    tmp_entity->setAutoExclusive(true);
    connect(tmp_entity , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
    this->entities->append(tmp_entity);
    }

    QIcon q2(":/icons/Computer.png");


    for (int i=0;i<2 ;i++)
    {

    QPushButton* tmp_entity =new QPushButton(ui->entityBoxContent);
    ui->verticalLayout->addWidget(tmp_entity);
    tmp_entity->setMaximumSize(50,50);
    tmp_entity->setMinimumSize(50,50);
    QSize s(50,50);
    tmp_entity->setIconSize(s);
    tmp_entity->setCheckable(true);
    tmp_entity->setIcon(q2);
    tmp_entity->setAutoExclusive(true);
    connect(tmp_entity , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
    this->entities->append(tmp_entity);
    }



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
                   activeDialog->newEntity=(*entities)[i]->icon().pixmap(50,50);
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
