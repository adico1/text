/*
 * Copyright © 2017 Andrew Penkrat
 *
 * This file is part of Liri Text.
 *
 * Liri Text is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Liri Text is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Liri Text.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LANGUAGEDATABASEMAINTAINER_H
#define LANGUAGEDATABASEMAINTAINER_H

#include <QObject>
#include <QSqlDatabase>
#include <QFileSystemWatcher>

class LanguageDatabaseMaintainer : public QObject
{
    Q_OBJECT
public:
    explicit LanguageDatabaseMaintainer(const QString &path, QObject *parent = nullptr);
    ~LanguageDatabaseMaintainer();

signals:
    void dbUpdated();
protected:
    void initDB(const QString &path);
public slots:
    void init();
    void updateDB();
private:
    QStringList specsDirs;
    QFileSystemWatcher *watcher;
    QString m_connId, m_dbPath;
};

#endif // LANGUAGEDATABASEMAINTAINER_H
