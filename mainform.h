#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include  <QVector>
#include "ui_mainform.h"
#include  "projectstore.h"
#include "graphicsheet.h"
#include <QFileDialog>
#include "kservice.h"
#include "kparts/part.h"


namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm( QWidget *parent = 0);
    ~MainForm();

private slots:
    void on_actionOpen_Project_triggered();
    void on_tabWidget_2_currentChanged(int index);
    void on_tabWidget_2_tabCloseRequested(int index);
    void on_actionSave_triggered();
    void on_actionTerminal_triggered(bool checked);



private:
     Ui::MainForm *ui;
     QVector<ProjectStore*>* projectStores;
     QMap<int,ProjectStore*> projectSheetMap;

     void constructToolbar();
     void  createTerminal();



};


#endif // MAINFORM_H
