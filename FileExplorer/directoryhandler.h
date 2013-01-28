#ifndef DIRECTORYHANDLER_H
#define DIRECTORYHANDLER_H

#include <QMainWindow>
#include <QDir>

class directoryHandler
{
public:
    directoryHandler();
    directoryHandler(QString currentPath);
    QString getCurrentPath();
    void setCurrentPath(QString currentPath);
    void cdUp();
    void cd(QString directoryName);
    QStringList getEntryList();
    QFileInfoList getDriveList();
    void createDirectory(QString name);
private:
    QDir m_dir;
};

#endif // DIRECTORYHANDLER_H
