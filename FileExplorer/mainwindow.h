#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QDateTime>
#include "directoryhandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showRootDirectory();
    void showDirectory(QTreeWidgetItem* item);
    void showDrive(QString drivePath);
    void createDirectory();
    
private:
    Ui::MainWindow *ui;

    directoryHandler* m_currentDirectory;

    void updateGUI();
    void addFolder(QString fileName);
    void addFile(QString fileName, long size, QString date);
};

#endif // MAINWINDOW_H
