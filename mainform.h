#ifndef MAINFORM_H
#define MAINFORM_H
#include "activedialog.h"
#include <QDialog>
#include <QScrollArea>

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

    QVector<QPushButton *>* entities;

    bool selectionState;

public slots:
    void toggleSelectionState(bool selection);
    void toggleEntity(bool selection);
    
private:
    Ui::MainForm *ui;





};


#endif // MAINFORM_H
