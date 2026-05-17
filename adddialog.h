//
// Created by mradu1 on 5/17/26.
//

#ifndef ADDRESSBOOK_ADDDIALOG_H
#define ADDRESSBOOK_ADDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

class AddDialog : public QDialog
{
    Q_OBJECT
public:
    AddDialog(QWidget *parent = nullptr);

    QString name() const;
    QString address() const;
    void editAddress(const QString &name, const QString &address);

private:
    QLineEdit *nameText;
    QTextEdit *addressText;
};

#endif //ADDRESSBOOK_ADDDIALOG_H
