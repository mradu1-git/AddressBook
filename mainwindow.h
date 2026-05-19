//
// Created by mradu1 on 5/19/26.
//

#ifndef ADDRESSBOOK_MAINWINDOW_H
#define ADDRESSBOOK_MAINWINDOW_H

#include "addresswidget.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private slots:
    void updateActions(const QItemSelection &selection);
    void openFile();
    void saveFile();
private:
    void createMenus();
    AddressWidget *addressWidget;
    QAction *editAct;
    QAction *removeAct;
};

#endif //ADDRESSBOOK_MAINWINDOW_H
