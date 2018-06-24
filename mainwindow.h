#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_objectTypeComboBox_activated(const QString &arg1);
    void on_subdirectoriesCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QString selectedDirectory;
    QStringList currentContents;
    int folderCount;
    bool absolutePathOrNot;
    bool recursiveOrNot;
};

#endif // MAINWINDOW_H
