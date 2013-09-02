#include "scenetoolbar.h"



SceneToolbar::SceneToolbar()
{

    SceneToolbar::toolbar= new QToolBar();
    actionSelection = new QAction( SceneToolbar::toolbar);
    actionSelection->setObjectName(QString::fromUtf8("actionSelection"));
    actionSelection->setCheckable(true);
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/mouse_pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionSelection->setIcon(icon);
    actionLink = new QAction( SceneToolbar::toolbar);
    actionLink->setObjectName(QString::fromUtf8("actionLink"));
    actionLink->setCheckable(true);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/icons/insert-link-2.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionLink->setIcon(icon1);

    actionDotLayout = new QAction( SceneToolbar::toolbar);
    actionDotLayout->setObjectName(QString::fromUtf8("actionDotLayout"));
    //actionDotLayout->setCheckable(true);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icons/dotlayout.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionDotLayout->setIcon(icon2);
    actionDotLayout->setText(QApplication::translate("MainForm", "DotLayout", 0, QApplication::UnicodeUTF8));



    actionNeatoLayout = new QAction( SceneToolbar::toolbar);
    actionNeatoLayout->setObjectName(QString::fromUtf8("actionNeatoLayout"));
  //  actionNeatoLayout->setCheckable(true);
    QIcon icon7;
    icon7.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionNeatoLayout->setIcon(icon2);
    actionNeatoLayout->setText(QApplication::translate("MainForm", "NeatoLayout", 0, QApplication::UnicodeUTF8));


    actionfdpLayout = new QAction( SceneToolbar::toolbar);
    actionfdpLayout->setObjectName(QString::fromUtf8("actionfdpLayout"));
   // actionfdpLayout->setCheckable(true);
    QIcon icon8;
    icon8.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionfdpLayout->setIcon(icon2);
    actionfdpLayout->setText(QApplication::translate("MainForm", "FDPLayout", 0, QApplication::UnicodeUTF8));


    actionsfdpLayout = new QAction( SceneToolbar::toolbar);
    actionsfdpLayout->setObjectName(QString::fromUtf8("actionsfdpLayout"));
    //actionsfdpLayout->setCheckable(true);
    QIcon icon9;
    icon9.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionsfdpLayout->setIcon(icon2);
    actionsfdpLayout->setText(QApplication::translate("MainForm", "SFDPLayout", 0, QApplication::UnicodeUTF8));

    actionelasticLayout = new QAction( SceneToolbar::toolbar);
    actionelasticLayout->setObjectName(QString::fromUtf8("actionelasticLayout"));
    //actionelasticLayout->setCheckable(true);
    QIcon icon10;
    icon10.addFile(QString::fromUtf8(":/icons/osa_lifecycle.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionelasticLayout->setIcon(icon2);
    actionelasticLayout->setText(QApplication::translate("MainForm", "ElasticLayout", 0, QApplication::UnicodeUTF8));

    actionAutoLink = new QAction( SceneToolbar::toolbar);
    actionAutoLink->setObjectName(QString::fromUtf8("actionAutoLink"));
    QIcon icon4;
    icon4.addFile(QString::fromUtf8(":/icons/insert-link.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionAutoLink->setIcon(icon4);
    actionRemove = new QAction( SceneToolbar::toolbar);
    actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
    QIcon icon5;
    icon5.addFile(QString::fromUtf8(":/icons/osa_lightning.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionRemove->setIcon(icon5);
    actionAutoZoom = new QAction( SceneToolbar::toolbar);
    actionAutoZoom->setObjectName(QString::fromUtf8("actionAutoZoom"));
    QIcon icon6;
    icon6.addFile(QString::fromUtf8(":/icons/star.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionAutoZoom->setIcon(icon6);

    actionSelection->setText(QApplication::translate("MainForm", "Selection", 0, QApplication::UnicodeUTF8));
    actionLink->setText(QApplication::translate("MainForm", "Link", 0, QApplication::UnicodeUTF8));

    //actionSave->setText(QApplication::translate("MainForm", "Save", 0, QApplication::UnicodeUTF8));
    actionAutoLink->setText(QApplication::translate("MainForm", "AutoLink", 0, QApplication::UnicodeUTF8));
    actionRemove->setText(QApplication::translate("MainForm", "Remove", 0, QApplication::UnicodeUTF8));
    actionAutoZoom->setText(QApplication::translate("MainForm", "AutoZoom", 0, QApplication::UnicodeUTF8));

     SceneToolbar::toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
     SceneToolbar::toolbar->addAction(actionSelection);
     SceneToolbar::toolbar->addAction(actionLink);


     SceneToolbar::toolbar->addAction(actionAutoLink);
     SceneToolbar::toolbar->addAction(actionRemove);
     SceneToolbar::toolbar->addAction(actionAutoZoom);

     SceneToolbar::toolbar->addAction(actionDotLayout);
     SceneToolbar::toolbar->addAction(actionNeatoLayout);
     SceneToolbar::toolbar->addAction(actionfdpLayout);
     SceneToolbar::toolbar->addAction(actionsfdpLayout);
     SceneToolbar::toolbar->addAction(actionelasticLayout);

     SceneToolbar::toolbar->setMovable(true);
     SceneToolbar::toolbar->setFloatable(true);

    /*QObject::connect(actionSelection, SIGNAL(toggled(bool)), graphicsView, SLOT(setSelectMode(bool)));
    QObject::connect(actionLink, SIGNAL(toggled(bool)), scene, SLOT(setLinkMode(bool)));
    QObject::connect(actionRemove,SIGNAL(triggered()), scene, SLOT(removeSelected()));
    QObject::connect(actionAutoZoom,SIGNAL(triggered()), scene, SLOT(autoZoom()));
    QObject::connect(actionAutoLink,SIGNAL(triggered()), this, SLOT(autoLink()));
    QObject::connect(actionDotLayout, SIGNAL(triggered()), this, SLOT(dotLayout()));
    QObject::connect(actionNeatoLayout, SIGNAL(triggered()), this, SLOT(neatoLayout()));
    QObject::connect(actionfdpLayout, SIGNAL(triggered()), this, SLOT(fdpLayout()));
    QObject::connect(actionsfdpLayout, SIGNAL(triggered()), this, SLOT(sfdpLayout()));
    QObject::connect(actionelasticLayout, SIGNAL(triggered()), this, SLOT(elasticLayout()));*/

   // actionSelection->setChecked(true);

}
