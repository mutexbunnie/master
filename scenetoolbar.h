#ifndef SCENETOOLBAR_H
#define SCENETOOLBAR_H

#include <QToolBar>
#include <QAction>
#include <QApplication>


class SceneToolbar
{

public:
    static SceneToolbar& getInstance()
            {
                static S    instance;
                return instance;
            }
   SceneToolbar();


private:

   S() {}
   S(S const&);              // Don't Implement.
   void operator=(S const&); // Don't implement

    /*static QAction *actionLink;
    static QAction *actionSelection;
    static QAction *actionDotLayout;
    static QAction *actionNeatoLayout;
    static QAction *actionfdpLayout;
    static QAction *actionsfdpLayout;
    static QAction *actionelasticLayout;
    static QAction *actionAutoLink;
    static QAction *actionRemove;
    static QAction *actionAutoZoom;


};

#endif // SCENETOOLBAR_H

