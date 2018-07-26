#ifndef MOVIEPLAYERWIDGET_H
#define MOVIEPLAYERWIDGET_H

#include <QWidget>

namespace Ui {
class moviePlayerWidget;
}

class moviePlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit moviePlayerWidget(QWidget *parent = nullptr);
    ~moviePlayerWidget();

private:
    Ui::moviePlayerWidget *ui;
};

#endif // MOVIEPLAYERWIDGET_H
