#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>

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

private:
    Ui::LeftPanel *ui;
};

#endif // LEFTPANEL_H
