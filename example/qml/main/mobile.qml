import QtQuick 2.0

/**
 * This is the mobile version of the QML based Mana client.
 */
Client {
    id: client

    width: 800;
    height: 480;

    MainWindow { anchors.fill: parent; }
}
