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
    void playGif(void);

private:
    QString selectedGif;
    bool    gifExists;
    Ui::moviePlayerWidget *ui;
    QStringList readGifsInFolder();
    void selectRandomGif(void);
};

#endif // MOVIEPLAYERWIDGET_H
