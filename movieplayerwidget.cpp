#include "movieplayerwidget.h"
#include "ui_movieplayerwidget.h"

#include <QLabel>
#include <QMovie> //also includes QImage

moviePlayerWidget::moviePlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moviePlayerWidget)
{

    QLabel *moviePlayerLabel = new QLabel(this);
    QMovie *movie = new QMovie("/home/xen20/Documents/Randomizer/test3.gif");
    QImage *retrieveMovieParameters = new QImage("/home/xen20/Documents/Randomizer/test3.gif");

    QSize movieWidthAndHeight = retrieveMovieParameters->size();

    this->setFixedSize(movieWidthAndHeight);

    ui->setupUi(this);
    moviePlayerLabel->setMovie(movie);
    movie->start();
}

moviePlayerWidget::~moviePlayerWidget()
{
    delete ui;
}
