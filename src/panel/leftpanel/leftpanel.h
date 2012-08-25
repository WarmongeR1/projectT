#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
    class LeftPanel;
}

class MainWindow;

class LeftPanel : public QWidget
{
    Q_OBJECT

public:
    explicit LeftPanel(QWidget *parent, MainWindow *h);
    ~LeftPanel();

    /**
      @function
      Function for begin load project
      Load files, settings ant other
      */
    void loadProject(QString file);


private:
    Ui::LeftPanel *ui;
    QStandardItemModel *standardModel;

    /**
      @function
      Function for begin debug;
      Set test params and other
      */
    void debug();
};

#endif // LEFTPANEL_H
