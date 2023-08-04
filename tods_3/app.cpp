
#include "app.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSplitter>

App::App(QWidget *parent)
    : QWidget{parent}
{
    auto dir = QDir(QDir::currentPath());
    dir.cdUp();
    this->setWindowTitle("Charts visualizier");
    this->setWindowIcon(QIcon(dir.path() + "/tods_3/logo.ico"));

    this->filesComponent = new FilesComponent(this);
//    filesComponent->setFixedWidth(470);
//    this->filesComponent->setFixedSize(600, 600);
    QSplitter *splitter = new QSplitter(this);

//    this->fileList->setFixedHeight(700);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
    splitter->addWidget(filesComponent);

    //boxLa
//    this->setCentralWidget(splitter);
    this->resize(1000, 700);
}

