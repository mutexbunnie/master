#include "mainform.h"


MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm)
{
        ui->setupUi(this);
        createTerminal();
        constructToolbar();
        projectStores=new QVector<ProjectStore*>();
}


void MainForm::createTerminal()
{
    KService::Ptr service = KService::serviceByDesktopPath("konsolepart.desktop");
    KParts::ReadOnlyPart *m_part = service->createInstance<KParts::ReadOnlyPart>(0);
    QWidget* terminal1=m_part->widget();
    KParts::ReadOnlyPart *m_part2 = service->createInstance<KParts::ReadOnlyPart>(0);
    QWidget* terminal2=m_part2->widget();
    ui->tabWidget->addTab(terminal1,"Session 1");
    ui->tabWidget->addTab(terminal2,"Session 2");
}

void MainForm::constructToolbar()
{

}


MainForm::~MainForm()
{
   // delete ui;
}


void MainForm::on_actionOpen_Project_triggered()
{

    QString filepath=QFileDialog::getOpenFileName(this, "Open Project File","","Files (*.xml)");
    if (filepath !="")
    {
        ProjectStore* projectStore= new ProjectStore();
        projectStore->loadProject(filepath);
        projectStores->append(projectStore);

       for (int i=0; i<projectStore->projectSheets->size();i++)
        {
          ui->tabWidget_2->addTab((*(projectStore->projectSheets))[i]->graphicSheet->mainFrame,(*(projectStore->projectSheets))[i]->sheetname);

          //(*(projectStore->projectSheets))[i]->graphicSheet->addEntityToolButtons(ui->toolBar_2);
          projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);
          //ui->tabWidget_2->addTab(frame2,"Tables 1");
          //projectSheetMap.insert(ui->tabWidget_2->count()-1,projectStore);
        }

       for (int i=0;i<projectStore->entityTypes->size() ;i++)
        {

            QAction* tmp_Action =new QAction(this);
            tmp_Action->setCheckable(true);
            tmp_Action->setText(((*(projectStore->entityTypes))[i])->name);
            tmp_Action->setIcon(((*(projectStore->entityTypes))[i])->plain);
            ui->toolBar_2->addAction(tmp_Action);
        }
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

void MainForm::on_actionTerminal_triggered(bool checked)
{
    this->ui->widget_2->setVisible(checked);
}
