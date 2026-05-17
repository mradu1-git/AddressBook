//
// Created by mradu1 on 5/17/26.
//

#include "newaddresstab.h"
#include "adddialog.h"

#include <QtWidgets>

NewAddressTab::NewAddressTab(QWidget *parent) : QWidget(parent)
{
    auto descriptionLabel = new QLabel(tr("There are currently no address in your addressbook. \n Click Add to add new Contacts"));
    auto addButton = new QPushButton(tr("Add"));

    connect(addButton, &QAbstractButton::clicked, this, &NewAddressTab::addEntry);
    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);
    setLayout(mainLayout);
}

void NewAddressTab::addEntry()
{
    AddDialog aDialog;
    if (aDialog.exec())
        emit sendDetails(aDialog.name(), aDialog.address());
}
