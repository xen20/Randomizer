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
    appSettings.loadSettings(browseParameters_);

    currentContents = browseFolder.folderContents(browseParameters_);

    ui->setupUi(this);
    updateUiOnProgramStartup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browsefolderButton_clicked()
{
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

    QStringList randFolder = getRandomFolders.returnRandomObjects(browseParameters_.objectCount,currentList);

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
    browseParameters_.objectCount = value;
}

void MainWindow::on_objectTypeComboBox_activated(const QString &objectType){
    folderBrowser browseFolder;

    browseParameters_.objectType = objectType;

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

void MainWindow::updateUiOnProgramStartup(){

    ui->selectedFolder->setText(browseParameters_.selectedDirectory);
    ui->objectTypeComboBox->setCurrentText(browseParameters_.objectType);
    ui->spinBox->setValue(browseParameters_.objectCount);
    ui->subdirectoriesCheckBox->setChecked(browseParameters_.recursiveOrNot);
    ui->absolutePathsCheckBox->setChecked(browseParameters_.absoluteOrNot);

}
