//
// Created by mradu1 on 5/17/26.
//

#include "adddialog.h"
#include <QtWidgets>

AddDialog::AddDialog(QWidget *parent) : QDialog(parent),
    nameText(new QLineEdit),
    addressText(new QTextEdit)
{
    auto nameLabel = new QLabel(tr("name"));
    auto addressLabel = new QLabel(tr("Address"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(addressLabel, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(addressText, 1, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
}
