#include <QApplication>
#include "mainform.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainForm mainForm;
    mainForm.show();


    return a.exec();
}
