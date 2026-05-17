//
// Created by mradu1 on 5/17/26.
//

#ifndef ADDRESSBOOK_NEWADDRESSTAB_H
#define ADDRESSBOOK_NEWADDRESSTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QVBoxLayout;
QT_END_NAMESPACE

class NewAddressTab : public QWidget
{
    Q_OBJECT
public:
    NewAddressTab(QWidget *parent = nullptr);

public slots:
    void addEntry();

signals:
    void sendDetails(const QString &name, const QString &address);
};

#endif //ADDRESSBOOK_NEWADDRESSTAB_H

    New