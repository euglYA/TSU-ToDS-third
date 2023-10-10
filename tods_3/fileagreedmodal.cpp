
#include "fileagreedmodal.h"

FileAgreeModal::FileAgreeModal(QWidget *parent)
    : QWidget{parent}
{
    this->vLayout = new QVBoxLayout(this);
    this->hLayout = new QHBoxLayout(this);

    this->agreeButton = new QPushButton("Согласен", this);
    this->disagreeButton = new QPushButton("Не согласен", this);
    this->textLabel = new QLabel("Размер файла слишком велик, его открытие может повлечь за собой некорректное отображение графиков. \n Согласны на открытие файла?", this);

    this->hLayout->addWidget(this->agreeButton);
    this->hLayout->addWidget(this->disagreeButton);

    this->vLayout->addWidget(this->textLabel);
    this->vLayout->addLayout(this->hLayout);

    this->window->resize(400, 400);
    this->window->setWindowTitle("Размер файла больше допустимого");

    this->window->setLayout(this->vLayout);

    this->window->setWindowModality(Qt::ApplicationModal);
    this->window->show();

    QObject::connect(this->agreeButton, &QPushButton::clicked, this, &FileAgreeModal::pressedAgree);
    QObject::connect(this->disagreeButton, &QPushButton::clicked, this, &FileAgreeModal::pressedDisagree);
}

bool FileAgreeModal::getBoolIsAgreed() {
    return this->isAgreed;
}

void FileAgreeModal::pressedAgree() {
    this->window->close();
    this->isAgreed = true;
}

void FileAgreeModal::pressedDisagree() {
    this->window->close();
    this->isAgreed = false;
}

