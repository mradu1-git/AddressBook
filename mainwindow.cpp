//
// Created by mradu1 on 5/19/26.
//

#include "mainwindow.h"

#include <QAction>
#include <QFileDialog>
#include <QMenuBar>

MainWindow::MainWindow() : QMainWindow(), addressWidget(new AddressWidget)
{
    setCentralWidget(addressWidget);
    createMenus();
    setWindowTitle(tr("Address Book"));
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAct = new QAction(tr("&Open"), this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    QAction *saveAct = new QAction(tr("&Save"), this);
    fileMenu->addAction(saveAct);
    connect(saveAct,&QAction::triggered, this, &MainWindow::saveFile);

    QAction *exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct,&QAction::triggered, this, &QWidget::close);

    QMenu *toolMenu = menuBar()->addMenu(tr("&Tools"));
    QAction *addAct = new QAction(tr("&Add Entry"), this);
    toolMenu->addAction(addAct);
    connect(addAct, &QAction::triggered, addressWidget, &AddressWidget::showAddEntryDialog);
    editAct = new QAction(tr("&Edit Entry"), this);
    editAct->setEnabled(addAct);
    connect(addAct, &QAction::triggered, addressWidget, &AddressWidget::showAddEntryDialog);

    editAct = new QAction(tr("&Edit Entry"), this);
    editAct->setEnabled(false);
    toolMenu->addAction(removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);
    connect(addressWidget, &AddressWidget::selectionChanged, this, &MainWindow::updateActions);
}

void MainWindow::openFile()
{
    addressWidget->readFromFile();
}

void MainWindow::saveFile()
{
    addressWidget->writeToFile();
}

void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty())
    {
        removeAct->setEnabled(true);
        editAct->setEnabled(true);
    } else
    {
        removeAct->setEnabled(false);
        editAct->setEnabled(false);
    }
}