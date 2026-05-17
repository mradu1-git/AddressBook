//
// Created by mradu1 on 5/12/26.
//

#ifndef ADDRESSBOOK_ADDRESSWIDGET_H
#define ADDRESSBOOK_ADDRESSWIDGET_H

#include "newaddresstab.h"
#include "tabelmodel.h"

#include <QItemSelection>
#include <QTabWidget>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QItemSelectionModel;
QT_END_NAMESPACE

class AddressWidget : public QTabWidget {
    Q_OBJECT
public:
    AddressWidget(QWidget *parent = nullptr);
    void readFromFile();
    void writeToFile();
public slots:
    void showAddEntryDialog();
    void addEntry(const QString &name, const QString &address);
    void editEntry();
    void removeEntry();

signals:
    void selectionChanged(const QItemSelection &selected);

private:
    void setupTabs();

    inline static QString fileName = QStandardPaths::standardLocations(QStandardPaths::TempLocation).value(0) + QStringLiteral("/addressbook.dat");
    TableModel *table;
    NewAddressTab *newAddressTab;
};

#endif //ADDRESSBOOK_ADDRESSWIDGET_H
