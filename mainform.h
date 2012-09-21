#ifndef MAINFORM_H
#define MAINFORM_H
#include "activedialog.h"
#include <QDialog>
#include <QScrollArea>
#include  <QVector>
#include  "entitytype.h"
#include "entitytypebutton.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm(QVector<EntityType *> *entityTypes, QWidget *parent = 0);
    ~MainForm();
    QScrollArea* scrollArea;
    ActiveDialog* activeDialog;

    QScrollArea* scrollArea2;
    ActiveDialog* activeDialog2;

    QVector<EntityTypeButton *>* entityTypeButtons;

    bool selectionState;

public slots:
    void toggleSelectionState(bool selection);
    void toggleEntity(bool selection);
    
private slots:
    void on_pushButton_toggled(bool checked);

private:
    Ui::MainForm *ui;





};


#endif // MAINFORM_H
