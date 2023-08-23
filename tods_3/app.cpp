
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

    this->iocTool = new IOCTool;

    this->filesComponent = new FilesComponent(this);
    filesComponent->setFixedWidth(459);
    this->chartsComponent = new ChartsComponent(this);

    QSplitter *splitter = new QSplitter(this);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
    splitter->addWidget(filesComponent);
    splitter->addWidget(chartsComponent);

    this->setCentralWidget(splitter);
    this->resize(1000, 700);

    QObject::connect(this->filesComponent, &FilesComponent::fileSelected, this, &App::chartDataChanger);
    QObject::connect(this, &App::updateFactoryType, this->iocTool, &IOCTool::changeFactoryType);
    QObject::connect(this, &App::updateChartData, this->chartsComponent, &ChartsComponent::changeChartData);
}

void App::chartDataChanger(QFileInfo selectedFile) {

    qDebug() << "File: " << selectedFile.fileName();
    int maxSize = 109000;
    emit updateFactoryType(selectedFile, maxSize);

    QMap<QString, QVariant> data;

    data = this->iocTool->getObject()->extractData(selectedFile);

    qDebug() << data;

    if (data.size() > 0)
        emit updateChartData(data);
}

