#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //new directoryHandler on root
    m_currentDirectory = new directoryHandler();

    //set up fileTreeWidget
    ui->fileTreeWidget->setColumnCount(4);
    ui->fileTreeWidget->setHeaderLabels(QStringList() << "Name" << "Size" << "Type" << "Last Modification");
    ui->fileTreeWidget->header()->resizeSection(0,250);

    updateGUI();

    //set up driveComboBox
    foreach(QFileInfo entry,  m_currentDirectory->getDriveList()) {
        if (entry.isWritable()) {
            ui->driveComboBox->addItem(entry.absoluteFilePath());
        }
    }

   //event handling
    connect(ui->showRootDirectoryButton,
            SIGNAL(clicked()),
            this,SLOT(showRootDirectory()));

    connect(ui->fileTreeWidget,
            SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            this,SLOT(showDirectory(QTreeWidgetItem*)));

    connect(ui->driveComboBox, SIGNAL(currentIndexChanged(QString)),
            this,SLOT(showDrive(QString)));

    connect(ui->createDirectoryButton,SIGNAL(clicked()),
            this,SLOT(createDirectory()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGUI() {

    //alte einträge löschen
    while(int count = ui->fileTreeWidget->topLevelItemCount()) {
        delete ui->fileTreeWidget->takeTopLevelItem(count - 1);
    }

    //positionslabel
    ui->rootLabel->setText(m_currentDirectory->getCurrentPath());

    //items erstellen
    QStringList ls = m_currentDirectory->getEntryList();
    foreach(QFileInfo entry, ls) {
        if (entry.isFile()) {
            addFile(entry.fileName(), entry.size(),entry.lastModified().toString("dd/MM/yyyy   hh:mm"));
        } else if (entry.isDir()) {
            addFolder(entry.fileName());
        }
    }

    //spaltenbreite anpassen
    ui->fileTreeWidget->resizeColumnToContents(1);
    ui->fileTreeWidget->resizeColumnToContents(2);
    ui->fileTreeWidget->resizeColumnToContents(3);
}

void MainWindow::addFolder(QString fileName) {
    QTreeWidgetItem* folder = new QTreeWidgetItem(ui->fileTreeWidget);
    folder->setIcon(0,QIcon(":/resources/folderIcon.png"));
    folder->setText(0,fileName);
    folder->setText(1,"");
    folder->setText(2,"Folder");
    ui->fileTreeWidget->addTopLevelItem(folder);
}

void MainWindow::addFile(QString fileName, long size, QString date) {
    QTreeWidgetItem* file = new QTreeWidgetItem(ui->fileTreeWidget);
    file->setText(0,fileName);

    file->setText(1,QString::number(size / 1024).append(" kb"));
    file->setText(2,"File");
    file->setText(3,date);
    file->setIcon(0,QIcon(":/resources/fileIcon.png"));
    ui->fileTreeWidget->addTopLevelItem(file);
}


void MainWindow::showRootDirectory() {
    m_currentDirectory->cdUp();
    updateGUI();
}

void MainWindow::showDirectory(QTreeWidgetItem* item) {
    if (item->text(2).operator ==("Folder")) {
        m_currentDirectory->cd(item->text(0));
        updateGUI();
    }
}

void MainWindow::showDrive(QString drivePath) {
    m_currentDirectory->cd(drivePath);
    updateGUI();
}

void MainWindow::createDirectory() {
    m_currentDirectory->createDirectory("HALLO");
    updateGUI();
}
