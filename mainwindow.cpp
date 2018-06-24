#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "folderbrowser.h"
#include "folderhistory.h"
#include "folderrandomizer.h"
#include "filebrowser.h"
#include <QString>
#include <QStringList>
#include <QApplication>
#include <QFileDialog>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browsefolderButton_clicked()
{
    folderBrowser browseFolder;
    static int    browseFunctionFirstCall = 0;
    QString home = browseFolder.getHomefolder();

    selectedDirectory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), home,
                                                      QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    if (browseFunctionFirstCall == 0){
        //defaults the selected object type to Directory on first press of browse button
        currentContents = browseFolder.folderContents(selectedDirectory);
        ++browseFunctionFirstCall;
    }

    ui->selectedFolder->setText(selectedDirectory);
}

void MainWindow::on_foldergenButton_clicked(){

    folderHistory getHistory(currentContents);

    getHistory.readHistory();
    QStringList currentList = getHistory.compareNewAndOldFolders();
    folderRandomizer getRandomFolders;

    QStringList randFolder = getRandomFolders.returnRandomObjects(folderCount,currentList);

    for(int index = 0; index < randFolder.size(); index++){
        ui->selectedObjects->append(randFolder[index]);
    }

    getHistory.writeHistory(randFolder);
}

void MainWindow::on_clearFolderHistory_clicked(){
    folderHistory clearHistory;
    clearHistory.clearHistory();

    ui->selectedObjects->clear();
}

void MainWindow::on_exitButton_released()
{
    QApplication::exit();
}

void MainWindow::on_spinBox_valueChanged(int value){
    folderCount = value;
}

void MainWindow::on_objectTypeComboBox_activated(const QString &arg1){
    if(arg1 == "Directories"){
        folderBrowser browseFolder;
        currentContents = browseFolder.folderContents(selectedDirectory);
    }
    else if(arg1 == "Videos"){
        fileBrowser browseFile;
        currentContents = browseFile.getVideoFiles(selectedDirectory);
    }
    else if(arg1 == "Music"){
        //todo
    }
}
