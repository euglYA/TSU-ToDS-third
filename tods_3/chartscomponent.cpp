
#include "chartscomponent.h"
#include <QtCharts>

ChartsComponent::ChartsComponent(QWidget *parent)
    : QWidget{parent} {

    this->vLayout = new QVBoxLayout(this);
    this->hLayout = new QHBoxLayout(this);

    this->saveAsPDF = new QPushButton("Save as PDF", this);
    this->swapChartTheme = new QCheckBox("Swap theme", this);
    this->chooseChartType = new QComboBox(this);

    this->hLayout->addWidget(this->saveAsPDF);
    this->hLayout->addWidget(this->swapChartTheme);

    this->vLayout->addLayout(this->hLayout);
    this->vLayout->addWidget(this->chooseChartType);
}

