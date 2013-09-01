#include <QApplication>
#include "mainform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm mainForm;
    mainForm.showMaximized();
    mainForm.setFocus();
    return a.exec();
}


