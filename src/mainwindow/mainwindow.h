/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the Graphics Dojo project on Qt Labs.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 or 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/


#ifndef HTML_EDITOR_H
#define HTML_EDITOR_H

#include <QMainWindow>
#include "highlighter.h"


#if QT_VERSION < 0x040500
#error You must use Qt >= 4.5.0!
#endif

namespace Ui
{
     class MainWindow;
}
class Ui_MainWindow;
class Ui_Dialog;
class AboutDialog;

class QLabel;
class QSlider;
class QUrl;
class RightPanel;
class LeftPanel;

#include <QSystemTrayIcon>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    /**
      @function
      Create connects
      */
    void createConnect();
    /**
      @function
      Create actions for tray
      */
    void createActions();
    /**
      @function
      Init
      */
    void init();
    /**
      @function
      Create tray
      */
    void createTrayIcon(); // add actionts to tray menu

    void debug();
    void setupActions();
    void setupToolBar();
    void setupMenu();
    bool load(const QString &f);
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);
    void execCommand(const QString&);
    void execCommand(const QString &cmd, const QString &arg);
    bool queryCommandState(const QString&);

private slots:

    /**
      @function
      Show dialog for open project (qhp file)
      */
    void openProject();

    /**
      @fucntion
      Open project. Load tree, parse.
      @param file   qhp file project
      */
    void openProject(QString file);
    /**
      @function
      Save project (export qhp and other file)
      */
    void saveProject();
    /**
      @function
      Function for new html file
      */
    void fileNew();

    /**
      @function
      Function for open html file
      */
    void fileOpen();
    /**
      @function
      Function for save file
      */
    bool fileSave();
    /**
      @function
      Function for save as file
      */
    bool fileSaveAs();
    ///tray
    /**
      @function
      Hide UI
      */
    void showHide(QSystemTrayIcon::ActivationReason);


    void editSelectAll();
    void styleParagraph();
    void styleHeading1();
    void styleHeading2();
    void styleHeading3();
    void styleHeading4();
    void styleHeading5();
    void styleHeading6();
    void stylePreformatted();
    void styleAddress();

    void formatStrikeThrough();
    void formatAlignLeft();
    void formatAlignCenter();
    void formatAlignRight();
    void formatAlignJustify();
    void formatIncreaseIndent();
    void formatDecreaseIndent();
    void formatNumberedList();
    void formatBulletedList();
    void formatFontName();
    void formatFontSize();
    void formatTextColor();
    void formatBackgroundColor();
    void insertImage();
    void createLink();
    void insertHtml();
    void zoomOut();
    void zoomIn();
    void adjustActions();
    void adjustSource();
    void changeTab(int);
    void openLink(const QUrl&);
    void changeZoom(int);

    /**
      @function
      Show about dialog
      */
    void showAbout();

    /**
      @fucntion
      Show home page prog.
      Used QDesktopServise
      */
    void showHomePage();

private:
    Ui::MainWindow *ui;
    QString fileName;
    bool sourceDirty;
    QLabel *zoomLabel;
    QSlider *zoomSlider;
    Highlighter *highlighter;
    Ui_Dialog *ui_dialog;
    QDialog *insertHtmlDialog;

    AboutDialog *gui_about; // about dialog
    RightPanel *gui_rightPanel;
    LeftPanel *gui_leftPanel;

    QDockWidget *dwLeft, *dwRight; /// dockwidget (panels)

    //tray
    QSystemTrayIcon *trIcon;
    QMenu *trayIconMenu;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

};

#endif // HTML_EDITOR_H
