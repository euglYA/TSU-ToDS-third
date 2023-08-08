
#include "filescomponent.h"

FilesComponent::FilesComponent(QWidget *parent)
    : QListWidget{parent} {

    QString homePath = QDir::homePath();
    QStringList filters;
    filters << "*.json" << "*.sqlite";

    this->boxLayout = new QVBoxLayout(this);

    this->chooseDirectoryButton = new QPushButton("Open folder...", this);
    this->chooseDirectoryButton->setFixedSize(100, 30);

    this->fsModel = new QFileSystemModel(this);
    this->fsModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    this->fsModel->setNameFilters(filters);
    this->fsModel->setNameFilterDisables(false);
    this->fsModel->setRootPath(homePath);

    this->tableView = new QTableView();
    this->tableView->setModel(this->fsModel);
    this->tableView->setRootIndex(this->fsModel->setRootPath(homePath));

    this->pathLabel = new QLabel("Current path: " + homePath, this);

    this->boxLayout->addWidget(this->chooseDirectoryButton);
    this->boxLayout->addWidget(this->tableView);
    this->boxLayout->addWidget(this->pathLabel);
}

