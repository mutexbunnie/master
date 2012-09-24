#include <QApplication>
#include "mainform.h"
#include "projectstore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ProjectStore* projectStore= new ProjectStore();
    projectStore->loadProject("projecttest.xml");

    MainForm mainForm(projectStore);

    mainForm.showMaximized();


    return a.exec();
}
