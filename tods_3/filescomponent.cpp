
#include "filescomponent.h"

FilesComponent::FilesComponent(QWidget *parent)
    : QListWidget{parent} {

    QString homePath = QDir::homePath();
    QStringList filters;
    filters << "*.json" << "*.sqlite";

    this->boxLayout = new QVBoxLayout(this);

    this->chooseDirectoryButton = new QPushButton("Open folder...", this);
    this->chooseDirectoryButton->setFixedSize(100, 30);

    this->qfsModel = new QFileSystemModel(this);
    this->qfsModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    this->qfsModel->setNameFilters(filters);
    this->qfsModel->setNameFilterDisables(false);
    this->qfsModel->setRootPath(homePath);

    this->qtableView = new QTableView();
    this->qtableView->setModel(this->qfsModel);
    this->qtableView->setRootIndex(this->qfsModel->setRootPath(homePath));

    this->pathLabel = new QLabel("Current path: " + homePath, this);

    this->boxLayout->addWidget(this->chooseDirectoryButton);
    this->boxLayout->addWidget(this->qtableView);
    this->boxLayout->addWidget(this->pathLabel);
}

