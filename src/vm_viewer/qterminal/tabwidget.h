/***************************************************************************
 *   Copyright (C) 2006 by Vladimir Kuznetsov                              *
 *   vovanec@gmail.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef TAB_WIDGET
#define TAB_WIDGET

#include <QTabWidget>
#include <QMap>

#include "properties.h"

class TermWidgetHolder;
class QAction;
class QActionGroup;


class TabWidget : public QTabWidget
{
Q_OBJECT
public:
    TabWidget(QWidget* parent = Q_NULLPTR,
              QString  _name = QString());

    TermWidgetHolder * terminalHolder();

public slots:
    int addNewTab(const QString& shell_program = QString());
    void removeTab(int);
    void removeCurrentTab();
    void removeFinished();
    void renameSession();
    void setWorkDirectory(const QString&);

    void copySelection();
    void pasteClipboard();
    void pasteSelection();
    void zoomIn();
    void zoomOut();
    void zoomReset();

    void changeTabPosition(QAction *);
    void changeScrollPosition(QAction *);
    void propertiesChanged();

    void clearActiveTerminal();

signals:
    void closeTabNotification();

private:
    const QString tabName;
    QString work_dir;
};

#endif
