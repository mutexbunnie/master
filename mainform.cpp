#include "mainform.h"
#include "ui_mainform.h"
#include <QPainter>
#include "entitytypebutton.h"
#define PI 3.14159265
#include <QDebug>
#include "graphicsview.h"
#include <mysqldatasource.h>


MainForm::MainForm(ProjectStore* projectStore, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
        ui->setupUi(this);
        ui->actionSelection->setChecked(true);
        QGraphicsView* graphicsView = new GraphicsView();
        ui->tabWidget->addTab(graphicsView,"Sheet 1");
        //connect(ui->actionSelection, SIGNAL(toggled(bool)), this, SLOT(toggleSelectionState(bool)));
        this->entityTypeButtons = new QVector<EntityTypeButton*>();
        ui->entityBoxLayout->setAlignment(Qt::AlignTop);


graphicsView -> setMinimumSize(400, 400);

        /*  qDebug()  <<"rowcount" <<model->rowCount();
        for (int row = 0; row < 2000; row++)
        {
        model=new QStandardItemModel(0, 1);
        model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

        QStandardItem *item = new QStandardItem();
        item->setData(QString("row %0").arg(row),Qt::EditRole);
        ///item->setData(*normal,Qt::DecorationRole);
        // item->setData(*selected,34);
        model->setItem(row, 0, item);
        }
        qDebug()  <<"rowcount" <<model->rowCount();
        // for (int i=0; i<5 ;i++)
        //{// }*/

        for (int i=0;i<projectStore->entityTypes->size() ;i++)
        {
            qDebug()  << projectStore->entityTypes->at(i)->name;
            EntityTypeButton* tmp_entityButton =new EntityTypeButton(ui->entityBoxContent,(*(projectStore->entityTypes))[i]);
            ui->entityBoxLayout->addWidget(tmp_entityButton);
            connect(tmp_entityButton , SIGNAL(toggled(bool)), this, SLOT(toggleEntity(bool)));
            this->entityTypeButtons->append(tmp_entityButton);

            /*for (int k=0; k<10 ;k++)
            {
                Entity* tmp_entity = new Entity(activeDialog,(*(projectStore->entityTypes))[i]);
                activeDialog->addEntity(tmp_entity,qrand() % 1024,qrand() % 1024);
            }*/

            //QString location= (*(projectStore->entityTypes))[i]->datalocation;
            /*QVector<QVector<QVariant>*>*  tmp_fields=((*(projectStore->entityTypes))[i])->datasource->getFields(location," 1=1 ");

            for (int k=0; k<tmp_fields->size() ;k++)
            {
                Entity* tmp_entity = new Entity(activeDialog,
                for (int j=0; j<(*tmp_fields)[k]->size();j++)
                {
                    qDebug() <<((*(*tmp_fields)[k])[j]).toString();
                    if ((*(*(projectStore->entityTypes))[i]->fieldMap->fieldDescriptions)[j]->fieldType==0)
                        tmp_entity->addField(  ((*(*tmp_fields)[k])[j]).toString() ,);
                    else
                        tmp_entity->addField( ((*(*tmp_fields)[k])[j]).toInt()  );
                }
            }*/
            /*fixxxx*/
            scene= new  GraphicsScene(0, ((MysqlDataSource*)(((*(projectStore->entityTypes))[i])->datasource))->model);
        }

        /*scene= new  GraphicsScene(0,model);*/
        scene->setSceneRect(0,0,900,900);
        graphicsView->setScene(scene);
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


MainForm::~MainForm()
{
   // delete ui;
}

void MainForm::on_pushButton_toggled(bool checked)
{
    if (checked)  ui->entityBox->show();
    else ui->entityBox->hide();


}
