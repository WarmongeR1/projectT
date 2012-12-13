#include "leftpanel.h"
#include "ui_leftpanel.h"

#include "mainwindow.h"
#include "common.h" /// common function. example: parse project file

#include <QStandardItemModel>
#include <QDebug>

LeftPanel::LeftPanel(QWidget *parent, MainWindow *h):
    QWidget(parent),
    ui(new Ui::LeftPanel)
{
    ui->setupUi(this);
}
//------------------------------------------------------------------------------
LeftPanel::~LeftPanel()
{
    delete ui;
}
//------------------------------------------------------------------------------
void LeftPanel::loadProject(QString file)
{
    parseProjectFile(file);
    filename = file;
    debug();
}
//------------------------------------------------------------------------------
void LeftPanel::debug()
{
    qDebug() << "Activate debug: leftPanel";

    standardModel = new QStandardItemModel ;
//    standardModel = parseToc(&getTextFromFile(filename)) ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();

    //defining a couple of items
    QStandardItem *americaItem = new QStandardItem("America");
    QStandardItem *mexicoItem =  new QStandardItem("Canada");
    QStandardItem *usaItem =     new QStandardItem("USA");
    QStandardItem *bostonItem =  new QStandardItem("Boston");
    QStandardItem *europeItem =  new QStandardItem("Europe");
    QStandardItem *italyItem =   new QStandardItem("Italy");
    QStandardItem *romeItem =    new QStandardItem("Rome");
    QStandardItem *veronaItem =  new QStandardItem("Verona");

    //building up the hierarchy
    rootNode->    appendRow(americaItem);
    rootNode->    appendRow(europeItem);
    americaItem-> appendRow(mexicoItem);
    americaItem-> appendRow(usaItem);
    usaItem->     appendRow(bostonItem);
    europeItem->  appendRow(italyItem);
    italyItem->   appendRow(romeItem);
    italyItem->   appendRow(veronaItem);

    //register the model
    ui->treeViewProject->setModel(standardModel);
    ui->treeViewProject->expandAll();

}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
