#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "folderbrowser.h"
#include "folderhistory.h"
#include "folderrandomizer.h"
#include <QString>
#include <QStringList>
#include <QApplication>
#include <QFileDialog>


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
    Folderbrowser browse;
    QString home = browse.getHomefolder(); //starts browsing off at home
    QString selectedDirectory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), home,
                                                      QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks); //selects our directory

    QStringList currentContents = browse.folderContents(selectedDirectory);
    currentContents_ = currentContents;
    ui->selectedFolder->setText(selectedDirectory);
}

void MainWindow::on_foldergenButton_clicked(){

    folderHistory getHistory(currentContents_, "C:\\Users\\Mom-TV\\Desktop\\test.txt");
    getHistory.readHistory();
    QStringList currentList = getHistory.compareNewOld();
    folderRandomizer getRandomFolders;

    QStringList randFolder = getRandomFolders.returnRandomObjects(folderCount,currentList);

    for(int index = 0; index < randFolder.size(); index++){
        ui->selectedObjects->append(randFolder[index]);
    }

    getHistory.writeHistory(randFolder);
}

void MainWindow::on_clearFolderHistory_clicked(){
    folderHistory clearHistory("C:\\Users\\Mom-TV\\Desktop\\test.txt");
    clearHistory.clearHistory();
}

void MainWindow::on_exitButton_released()
{
    QApplication::exit();
}

void MainWindow::on_spinBox_valueChanged(int value){
    folderCount = value;
}
