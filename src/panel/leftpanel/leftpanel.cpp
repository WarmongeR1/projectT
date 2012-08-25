#include "leftpanel.h"
#include "ui_leftpanel.h"

#include "mainwindow.h"
LeftPanel::LeftPanel(QWidget *parent, MainWindow *h):
    QWidget(parent),
    ui(new Ui::LeftPanel)
{
    ui->setupUi(this);
}

LeftPanel::~LeftPanel()
{
    delete ui;
}
