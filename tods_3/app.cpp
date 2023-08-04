
#include "app.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSplitter>

App::App(QWidget *parent)
    : QMainWindow{parent}
{
    auto dir = QDir(QDir::currentPath());
    dir.cdUp();
    this->setWindowTitle("Charts visualizer");
    this->setWindowIcon(QIcon(dir.path() + "/tods_3/logo.ico"));

    this->filesComponent = new FilesComponent(this);
    filesComponent->setFixedWidth(459);
    QSplitter *splitter = new QSplitter(this);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
    splitter->addWidget(filesComponent);

    this->setCentralWidget(splitter);
    this->resize(1000, 700);
}

