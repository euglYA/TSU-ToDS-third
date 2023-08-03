
#include "app.h"
#include <QHBoxLayout>
#include <QLabel>

App::App(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *label = new QLabel("sosisosisosi", this);
    layout->addWidget(label);

}

