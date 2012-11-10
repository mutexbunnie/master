#include "mainform.h"
#include "ui_mainform.h"
#include "entitytypebutton.h"
#include "graphicsview.h"
#include <mysqldatasource.h>
#include <QTableView>
#include <QDebug>

MainForm::MainForm(ProjectStore* projectStore, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
        ui->setupUi(this);
        ui->actionSelection->setChecked(true);

        //connect(ui->actionSelection, SIGNAL(toggled(bool)), this, SLOT(toggleSelectionState(bool)));
        this->entityTypeButtons = new QVector<EntityTypeButton*>();
        ui->entityBoxLayout->setAlignment(Qt::AlignTop);


        QGraphicsView* graphicsView = new GraphicsView();
        graphicsView->setFocus();
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView -> setMinimumSize(400, 400);
        ui->tabWidget->addTab(graphicsView,"Sheet 1");
        scene= new  GraphicsScene(0);
        scene->setSceneRect(0,0,1024,1024);
        graphicsView->setScene(scene);

        for (int i=0;i<projectStore->entityTypes->size() ;i++)
        {
            EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent,(*(projectStore->entityTypes))[i]);
            ui->entityBoxLayout->addWidget(tmp_entityButton);
            connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
            this->entityTypeButtons->append(tmp_entityButton);

            QTableView* tableView = new QTableView();
            ui->tabWidget->addTab(tableView, projectStore->entityTypes->at(i)->name);
            //* FIX MYSQLSOURCE CAST*//
            tableView->setModel( ((MysqlDataSource*)(((*(projectStore->entityTypes))[i])->datasource))->model);
            scene->addModel(((MysqlDataSource*)(((*(projectStore->entityTypes))[i])->datasource))->model,projectStore->entityTypes->at(i));
        }
        QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        ui->entityBoxLayout->addItem(verticalSpacer);

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

