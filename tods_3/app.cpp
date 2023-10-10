
#include "app.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSplitter>
#include <QMessageBox>



App::App(QWidget *parent)
    : QMainWindow{parent}
{
    auto dir = QDir(QDir::currentPath());
    dir.cdUp();
    this->setWindowTitle("Charts visualizer");
    this->setWindowIcon(QIcon(dir.path() + "/tods_3/logo.ico"));

    this->iocTool = new IOCTool;

    this->filesComponent = new FilesComponent(this);
    this->filesComponent->setFixedWidth(459);
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

    qDebug() << "File: " << selectedFile.fileName() << " size: " << selectedFile.size();
    int maxFileSize = 10240; // it equals to 10KiB

    if (selectedFile.size() >= maxFileSize) {
        this->returnMessageBox(selectedFile.fileName(), "файл слишком большой \nМаксимальный размер файла: 10KiB");
        return;
    }


    emit updateFactoryType(selectedFile);

    QMap<QString, QVariant> data;

    data = this->iocTool->getObject()->extractData(selectedFile);

    qDebug() << data.size();

    if (data.size() < maxFileSize)
        emit updateChartData(data);
}

void App::returnMessageBox(QString text, QString secText) {
    QMessageBox msg;
    msg.setText(text + ": " + secText);
    msg.exec();
}

