/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created: Thu Oct 11 22:52:43 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionSelection;
    QAction *actionNew_Project;
    QAction *actionNew_Entity_Type;
    QAction *actionOpen_Project;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *actionArea;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *entityBox;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *entityBoxContent;
    QVBoxLayout *entityBoxLayout;
    QScrollArea *scrollArea;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(1024, 683);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainForm->sizePolicy().hasHeightForWidth());
        MainForm->setSizePolicy(sizePolicy);
        MainForm->setMouseTracking(false);
        actionSelection = new QAction(MainForm);
        actionSelection->setObjectName(QString::fromUtf8("actionSelection"));
        actionSelection->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/mouse_pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelection->setIcon(icon);
        actionNew_Project = new QAction(MainForm);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionNew_Entity_Type = new QAction(MainForm);
        actionNew_Entity_Type->setObjectName(QString::fromUtf8("actionNew_Entity_Type"));
        actionOpen_Project = new QAction(MainForm);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        centralWidget = new QWidget(MainForm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        actionArea = new QFrame(centralWidget);
        actionArea->setObjectName(QString::fromUtf8("actionArea"));
        actionArea->setMinimumSize(QSize(280, 208));
        actionArea->setFrameShape(QFrame::NoFrame);
        actionArea->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(actionArea);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(actionArea);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(20, 0));
        frame_2->setMaximumSize(QSize(20, 16777215));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setFlat(false);

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addWidget(frame_2);

        entityBox = new QFrame(actionArea);
        entityBox->setObjectName(QString::fromUtf8("entityBox"));
        entityBox->setMinimumSize(QSize(80, 98));
        entityBox->setMaximumSize(QSize(80, 16777215));
        entityBox->setFrameShape(QFrame::StyledPanel);
        entityBox->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(entityBox);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_2 = new QScrollArea(entityBox);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(80, 0));
        scrollArea_2->setMaximumSize(QSize(80, 16777215));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setFrameShadow(QFrame::Plain);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignCenter);
        entityBoxContent = new QWidget();
        entityBoxContent->setObjectName(QString::fromUtf8("entityBoxContent"));
        entityBoxContent->setGeometry(QRect(0, 0, 80, 614));
        entityBoxLayout = new QVBoxLayout(entityBoxContent);
        entityBoxLayout->setObjectName(QString::fromUtf8("entityBoxLayout"));
        entityBoxLayout->setContentsMargins(-1, 0, -1, -1);
        scrollArea_2->setWidget(entityBoxContent);

        verticalLayout_2->addWidget(scrollArea_2);


        horizontalLayout_2->addWidget(entityBox);

        scrollArea = new QScrollArea(actionArea);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMouseTracking(true);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        tabWidget = new QTabWidget();
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 910, 614));
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(false);
        scrollArea->setWidget(tabWidget);

        horizontalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(actionArea);

        MainForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainForm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainForm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainForm);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainForm->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionNew_Entity_Type);
        menuFile->addSeparator();
        mainToolBar->addAction(actionSelection);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Master", 0, QApplication::UnicodeUTF8));
        actionSelection->setText(QApplication::translate("MainForm", "Selection", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setText(QApplication::translate("MainForm", "New Project", 0, QApplication::UnicodeUTF8));
        actionNew_Entity_Type->setText(QApplication::translate("MainForm", "New Entity Type", 0, QApplication::UnicodeUTF8));
        actionOpen_Project->setText(QApplication::translate("MainForm", "Open Project", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainForm", "E\n"
"n\n"
"t\n"
"i\n"
"t\n"
"i\n"
"e\n"
"s", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainForm", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
