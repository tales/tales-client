/*
 *  Mana Mobile
 *  Copyright (C) 2010  Thorbjørn Lindeijer
 *
 *  This file is part of Mana Mobile.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include <QMessageBox>
#include <qdeclarative.h>

#ifndef QT_NO_OPENGL
#include <QGLWidget>
#endif

#include <enet/enet.h>

#include "qmlapplicationviewer.h"

#include "characterlistmodel.h"
#include "loginmanager.h"

static void registerTypes()
{
    qmlRegisterType<LoginManager>("Mana", 1, 0, "LoginManager");
    qmlRegisterUncreatableType<CharacterListModel>(
                "Mana", 1, 0, "CharacterListModel",
                QLatin1String("Use LoginManager.characterListModel"));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("Mana Mobile");
    app.setOrganizationDomain("manasource.org");

    if (enet_initialize() != 0)
    {
        QMessageBox::critical(0, app.applicationName(),
                              "An error occurred while initializing ENet.\n");
        return 1;
    }
    atexit(enet_deinitialize);

    registerTypes();

    QmlApplicationViewer viewer;
#ifndef QT_NO_OPENGL
    viewer.setViewport(new QGLWidget);
#endif
    viewer.setOrientation(QmlApplicationViewer::Auto);
    viewer.setMainQmlFile(QLatin1String("qml/main/main.qml"));
    viewer.setWindowTitle(app.applicationName());

    viewer.show();
    return app.exec();
}
