//
// Created by mradu1 on 5/18/26.
//

#ifndef ADDRESSBOOK_TABLEMODEL_H
#define ADDRESSBOOK_TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>

struct Contact
{
    QString name;
    QString address;

    bool operator==(const Contact& other) const
    {
        return name == other.name && address == other.address;
    }
};

inline QDataStream &operator<<(QDataStream &stream, const Contact &contact)
{
    return stream << contact.name << contact.address;
}

inline QDataStream &operator>>(QDataStream &stream, Contact &contact)
{
    return stream >> contact.name >> contact.address;
}

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject *parent = nullptr);
    TableModel(const QList<Contact> &contacts, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int row, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int positon, int row, const QModelIndex &index = QModelIndex()) override;
    const QList<Contact> &getContacts() const;

private:
    QList<Contact> contacts;
};

#endif //ADDRESSBOOK_TABLEMODEL_H
