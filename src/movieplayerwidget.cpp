#include "movieplayerwidget.h"
#include "ui_movieplayerwidget.h"
#include "folderrandomizer.h"
#include "folderbrowser.h"
#include "browseparameters.h"

#include <QLabel>
#include <QMovie>
#include <QCoreApplication>
#include <QDirIterator>
#include <QException>

moviePlayerWidget::moviePlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moviePlayerWidget)
{
    gifExists = false;
    ui->setupUi(this);
}

moviePlayerWidget::~moviePlayerWidget()
{
    delete ui;
}

void moviePlayerWidget::selectRandomGif(){
    folderRandomizer randomize;
    QStringList gifsInFolder = this->readGifsInFolder();
    QStringList randomGif;

    randomGif = randomize.returnRandomObjects(1, gifsInFolder);
    if (randomGif.length() > 0){
        selectedGif = randomGif[0];
        gifExists = true;
    }
    else {
        gifExists = false;
    }

}

QStringList moviePlayerWidget::readGifsInFolder(){
    QDir FolderPath(QApplication::applicationDirPath()+"/gifs");

    QStringList gifsRetrieved;
    browseParameters parameters;
    parameters.objectType = "Gifs";
    folderBrowser browse;

    gifsRetrieved = browse.returnObjects(parameters, FolderPath);

    return gifsRetrieved;
}

void moviePlayerWidget::playGif(){
    this->selectRandomGif();
    if (gifExists){
        QLabel *moviePlayerLabel = new QLabel(this);
        QMovie *movie = new QMovie(selectedGif);
        QImage *retrieveMovieParameters = new QImage(selectedGif);

        QSize movieWidthAndHeight = retrieveMovieParameters->size();

        this->setFixedSize(movieWidthAndHeight);
        moviePlayerLabel->setMovie(movie);
        movie->start();
    }
}
