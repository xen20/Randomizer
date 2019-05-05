#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = nullptr);
    void displayErrorMessage(QString message);
    ~MessageDialog();

private:
    Ui::MessageDialog *ui;
};

#endif // MESSAGEDIALOG_H
