#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "folderbrowser.h"
#include "folderhistory.h"
#include "folderrandomizer.h"
#include "settings.h"
#include "fonthandler.h"
#include "filecopyfunctions.h"

#include <QApplication>
#include <QFileDialog>
#include <QTextEdit>
#include <QCheckBox>
#include <QThread>  //allows sleep

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    guiSettings appSettings;
    appSettings.loadSettings(browseParameters_);

    currentContents = browseFolder.folderContents(browseParameters_);

    fontHandler chooseFontAndSize;
    chooseFontAndSize.setGlobalFont("Cantarell-Regular", 12);

    ui->setupUi(this);
    this->updateUiOnProgramStartup();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browsefolderButton_clicked(){

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

    listOfRandomObjects = getRandomFolders.returnRandomObjects(browseParameters_.objectCount,currentList);

    for(int index = 0; index < listOfRandomObjects.size(); index++){
        ui->selectedObjects->append(QString::number(index)+" "+listOfRandomObjects[index]);
    }

    getHistory.writeHistory(listOfRandomObjects);
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
    browseParameters_.objectCount = value;
}

void MainWindow::on_objectTypeComboBox_activated(const QString &objectType){

    browseParameters_.objectType = objectType;

    currentContents = browseFolder.folderContents(browseParameters_);
}

void MainWindow::updateUiOnProgramStartup(){

    ui->selectedFolder->setText(browseParameters_.selectedDirectory);
    ui->targetDestination->setText(browseParameters_.copyTargetDirectory);
    ui->objectTypeComboBox->setCurrentText(browseParameters_.objectType);
    ui->spinBox->setValue(browseParameters_.objectCount);
    ui->subdirectoriesCheckBox->setChecked(browseParameters_.recursiveOrNot);

}

void MainWindow::on_subdirectoriesCheckBox_toggled(bool checkBoxCheckedOrNot){

    browseParameters_.recursiveOrNot = checkBoxCheckedOrNot;

    currentContents = browseFolder.folderContents(browseParameters_);
}

void MainWindow::on_browseForDestination_clicked(){
    QString homeFolder = browseFolder.getHomefolder();

    browseParameters_.copyTargetDirectory = QFileDialog::getExistingDirectory(this, tr("Choose Destination Directory"), homeFolder,
                                                      QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->targetDestination->setText(browseParameters_.copyTargetDirectory);
}

void MainWindow::on_copyButton_clicked(){

    progressBar.move(this->rect().center() - progressBar.rect().center());

    fileCopyFunctions copier(&progressBar);
    if(browseParameters_.objectType == "Directories"){
        copier.folderCopy(listOfRandomObjects, browseParameters_.copyTargetDirectory);
    }
    else{
        copier.fileCopy(listOfRandomObjects, browseParameters_.copyTargetDirectory);
    }

    progressBar.close();

    playMovie.playGif();
    playMovie.show();
}
