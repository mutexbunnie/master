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
   // QScrollArea* scrollArea;
    //ActiveDialog* activeDialog;

    //QScrollArea* scrollArea2;
    //ActiveDialog* activeDialog2;

    //QStandardItemModel* model;
    GraphicsScene* scene;

    QVector<EntityTypeButton *>* entityTypeButtons;



    bool selectionState;

public slots:
    void toggleSelectionState(bool selection);
    void toggleEntity(bool selection);
    
private slots:
    void on_pushButton_toggled(bool checked);

    void on_actionLink_triggered(bool checked);

    void on_actionOpen_Project_triggered();


    void on_actionSave_triggered();

    void on_actionAutoLink_triggered();

private:
    Ui::MainForm *ui;

    ProjectStore* projectStore;



};


#endif // MAINFORM_H
