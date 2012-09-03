#ifndef MAINFORM_H
#define MAINFORM_H
#include "activedialog.h"
#include <QDialog>
#include <QScrollArea>
#include "entitytypebutton.h"

namespace Ui {
class MainForm;
}

class MainForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainForm(QDialog *parent = 0);
    ~MainForm();
    QScrollArea* scrollArea;
    ActiveDialog* activeDialog;

    QScrollArea* scrollArea2;
    ActiveDialog* activeDialog2;

    QVector<EntityTypeButton *>* entities;

    bool selectionState;

public slots:
    void toggleSelectionState(bool selection);
    void toggleEntity(bool selection);
    
private:
    Ui::MainForm *ui;





};


#endif // MAINFORM_H
