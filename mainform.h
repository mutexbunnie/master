#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QScrollArea>
#include  <QVector>
#include  "projectstore.h"
#include "entitytypebutton.h"
#include <QStandardItemModel>
#include "graphicsscene.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm( QWidget *parent = 0);
    ~MainForm();

    QVector<EntityTypeButton *>* entityTypeButtons;
    bool selectionState;
public slots:
    void toggleEntity(bool selection);

private slots:
    void on_actionOpen_Project_triggered();
    void on_actionSave_triggered();
    void on_pushButton_2_toggled(bool checked);
    void on_tabWidget_2_currentChanged(int index);
    void on_tabWidget_2_tabCloseRequested(int index);
    void on_actionSelection_toggled(bool selection);
    void on_actionLink_triggered();

    void on_actionAutoLink_triggered();


    void on_actionRemove_triggered();

private:
    Ui::MainForm *ui;
     QVector<ProjectStore*>* projectStores;
     QMap<int,ProjectStore*> projectSheetMap;
     GraphicsScene* scene;


};


#endif // MAINFORM_H
