#include "movieplayerwidget.h"
#include "ui_movieplayerwidget.h"
#include "folderrandomizer.h"
#include "folderbrowser.h"
#include "browseparameters.h"

#include <QLabel>
#include <QMovie>

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

    if(gifsInFolder.length() > 0 ){
        randomGif = randomize.returnRandomObjects(1, gifsInFolder);
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

    if (FolderPath.exists()){

        browseParameters parameters;
        parameters.objectType = "Gifs";
        folderBrowser browse;

        gifsRetrieved = browse.returnObjects(parameters, FolderPath);

        return gifsRetrieved;
    }
    else {
        return gifsRetrieved;
    }
}

bool moviePlayerWidget::attemptPlayGif(){

    this->selectRandomGif();
    bool playOrNot = false;
    if (gifExists){
        QLabel *moviePlayerLabel = new QLabel(this);
        QMovie *movie = new QMovie(selectedGif);
        QImage *retrieveMovieParameters = new QImage(selectedGif);

        QSize movieWidthAndHeight = retrieveMovieParameters->size();

        this->setFixedSize(movieWidthAndHeight);
        moviePlayerLabel->setMovie(movie);
        movie->start();

        playOrNot = true;
    }

    return playOrNot;
}
