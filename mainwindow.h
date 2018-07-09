#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "browseparameters.h"
#include "folderbrowser.h"

#include <QMainWindow>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_browsefolderButton_clicked();
    void on_foldergenButton_clicked();
    void on_clearFolderHistory_clicked();
    void on_exitButton_released();
    void on_spinBox_valueChanged(int value);
    void on_objectTypeComboBox_activated(const QString &objectType);
    void updateUiOnProgramStartup();
    void on_subdirectoriesCheckBox_toggled(bool checkBoxCheckedOrNot);
    void on_absolutePathsCheckBox_toggled(bool checkBoxCheckedOrNot);

private:
    Ui::MainWindow *ui;
    QStringList currentContents;
    browseParameters browseParameters_;
    folderBrowser browseFolder;
};

#endif // MAINWINDOW_H
