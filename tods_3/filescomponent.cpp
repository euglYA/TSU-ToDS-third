#include <QDebug>
#include "filescomponent.h"

FilesComponent::FilesComponent(QWidget *parent)
    : QListWidget{parent} {

    QString homePath = QDir::homePath();
    QStringList filters;
    filters << "*.json" << "*.sqlite";

    this->vLayout = new QVBoxLayout(this);

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

    this->vLayout->addWidget(this->chooseDirectoryButton);
    this->vLayout->addWidget(this->tableView);
    this->vLayout->addWidget(this->pathLabel);

    this->selectionModel = this->tableView->selectionModel();

    QObject::connect(this->chooseDirectoryButton, &QPushButton::clicked, this, &FilesComponent::onClickedChooseDirectory);
    QObject::connect(this->selectionModel, &QItemSelectionModel::currentChanged, this, &FilesComponent::onClickedFile);
}

void FilesComponent::onClickedChooseDirectory() {
    QString dir = QFileDialog::getExistingDirectory();
    if (!dir.isEmpty()) {
        this->fsModel->setRootPath(dir);
        this->tableView->setRootIndex(this->fsModel->index(dir));
        this->pathLabel->setText(dir);
    }
}

void FilesComponent::onClickedFile(const QModelIndex& selectedFile) {
    static QModelIndex lastChoosedFile;

    if (this->fsModel->fileInfo(selectedFile).isDir())
        return;

    if (lastChoosedFile != selectedFile) {
        emit FilesComponent::fileSelected(fsModel->fileInfo(selectedFile));
        lastChoosedFile = selectedFile;
    }
    qDebug() << "sosi";
}


