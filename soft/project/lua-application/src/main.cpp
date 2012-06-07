/*
    This file is part of LibQtLua.

    LibQtLua is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LibQtLua is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with LibQtLua.  If not, see <http://www.gnu.org/licenses/>.

    Additional Terms 7.b of GPLv3 applies to this file: Requiring
    preservation of specified reasonable legal notices or author
    attributions in that material or in the Appropriate Legal Notices
    displayed by works containing it;

    Copyright (C) 2008, Alexandre Becoulet <alexandre.becoulet@free.fr>

*/

#include <QtGui>
#include <QtLua/State>
#include "binder.h"
#include "script_editor.h"
#include "log_wnd.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtLua::State st;
    
    LogWnd * log = new LogWnd( 0, &st );
    ScriptEditor * se = new ScriptEditor( log, 0 );
    log->show();
    se->show();

    int res = app.exec();
    return res;
}

