#include <QApplication>
#include <QTableView>
#include "tablemodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create the list cleanly
    QList<Contact> temporaryContacts;

    // Explicitly create Contact instances to remove any ambiguity
    Contact c1;
    c1.name = "Arch User";
    c1.address = "123 Hyprland Way, Linux City";

    Contact c2;
    c2.name = "Gemini AI";
    c2.address = "101 Google Server Rack, Mountain View";

    temporaryContacts.append(c1);
    temporaryContacts.append(c2);

    // Pass the populated list to your model
    TableModel model(temporaryContacts);

    // Create the standalone grid window
    QTableView view;
    view.setModel(&model);

    view.setWindowTitle("Testing TableModel - Step 3 Complete!");
    view.resize(600, 300);
    view.show();

    return app.exec();
}