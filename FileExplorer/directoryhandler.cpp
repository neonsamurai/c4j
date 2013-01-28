#include "directoryhandler.h"
#include <stdio.h>
#include <iostream>
directoryHandler::directoryHandler()
{
    setCurrentPath(m_dir.rootPath());
    m_dir.makeAbsolute();
}

directoryHandler::directoryHandler(QString currentPath)
{
    setCurrentPath(currentPath);
    m_dir.makeAbsolute();
    if (!m_dir.exists()) throw (20);
}

QString directoryHandler::getCurrentPath() {
    return m_dir.currentPath();
}

void directoryHandler::setCurrentPath(QString currentPath) {
    m_dir.setCurrent(currentPath);
}

void directoryHandler::cdUp() {
    if (m_dir.currentPath() != m_dir.rootPath()) {
        cd("..");
    }
}

void directoryHandler::cd(QString directoryName) {
    m_dir.cd(directoryName);
    setCurrentPath(m_dir.path());
}


QStringList directoryHandler::getEntryList() {
    return m_dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries, QDir::DirsFirst);
}

QFileInfoList directoryHandler::getDriveList() {
    return m_dir.drives();
}

void directoryHandler::createDirectory(QString name) {
    m_dir.mkdir(name);
}

