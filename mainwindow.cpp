//
// Created by mradu1 on 5/12/26.
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
    
}
