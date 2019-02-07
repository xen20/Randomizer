#include "movieplayerwidget.h"
#include "ui_movieplayerwidget.h"
#include "folderrandomizer.h"

#include <QLabel>
#include <QMovie> //also includes QImage
#include <QCoreApplication>
#include <QDirIterator>

moviePlayerWidget::moviePlayerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::moviePlayerWidget)
{
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

    selectedGif = randomGif[0];
}

QStringList moviePlayerWidget::readGifsInFolder(){
    QDir gifFolderPath("/home/xen20/Documents/Randomizer/gifs");

    QStringList gifType;
    QStringList gifsRetrieved;
    gifType << "*.gif";

    gifFolderPath.setFilter(QDir::Files);
    gifFolderPath.setNameFilters(gifType);

        QDirIterator iter(gifFolderPath, QDirIterator::Subdirectories);

        while(iter.hasNext()){
            gifsRetrieved << iter.next();
        }

    return gifsRetrieved;
}

void moviePlayerWidget::playGif(){

    this->selectRandomGif();
    QLabel *moviePlayerLabel = new QLabel(this);
    QMovie *movie = new QMovie(selectedGif);
    QImage *retrieveMovieParameters = new QImage(selectedGif);

    QSize movieWidthAndHeight = retrieveMovieParameters->size();

    this->setFixedSize(movieWidthAndHeight);
    moviePlayerLabel->setMovie(movie);
    movie->start();
}
