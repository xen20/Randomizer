#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "folderbrowser.h"
#include "folderhistory.h"
#include "folderrandomizer.h"
#include "settings.h"
#include "gifplayer.h"

#include <QString>
#include <QStringList>
#include <QApplication>
#include <QFileDialog>
#include <QTextEdit>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    guiSettings appSettings;
    appSettings.loadSettings(browseParameters_, ui);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browsefolderButton_clicked()
{
    folderBrowser browseFolder;
    QString homeFolder = browseFolder.getHomefolder();

    browseParameters_.selectedDirectory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), homeFolder,
                                                      QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    currentContents = browseFolder.folderContents(browseParameters_);
    ui->selectedFolder->setText(browseParameters_.selectedDirectory);
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

void MainWindow::on_exitButton_released(){
    guiSettings appSettings;
    appSettings.saveSettings(browseParameters_);

    QApplication::exit();
}

void MainWindow::on_spinBox_valueChanged(int value){
    folderCount = value;
}

void MainWindow::on_objectTypeComboBox_activated(const QString &arg1){
    folderBrowser browseFolder;
    if(arg1 == "Directories"){
        browseParameters_.objectType = "Directories";
    }
    else if(arg1 == "Videos"){
        browseParameters_.objectType = "Videos";
    }
    else if(arg1 == "Music"){
        browseParameters_.objectType = "Music";
    }
    currentContents = browseFolder.folderContents(browseParameters_);
}

void MainWindow::on_subdirectoriesCheckBox_stateChanged(int arg1){
    folderBrowser browseFolder;

    if(ui->subdirectoriesCheckBox->isChecked()){
        browseParameters_.recursiveOrNot = true;
    }
    else{
        browseParameters_.recursiveOrNot = false;
    }

    currentContents = browseFolder.folderContents(browseParameters_);
}
