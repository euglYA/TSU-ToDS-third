
#include "chartscomponent.h"
#include <QtCharts>

ChartsComponent::ChartsComponent(QWidget *parent)
    : QWidget{parent} {

    this->vLayout = new QVBoxLayout(this);
    this->hLayout = new QHBoxLayout(this);

    this->saveAsPDF = new QPushButton("Сохранить в PDF", this);
    this->swapThemeLabel = new QLabel("Выберите тип диаграммы ", this);
    this->swapChartTheme = new QCheckBox("Черно-белый график", this);
    this->chooseChartType = new QComboBox(this);
    this->chooseChartType->setFixedWidth(150);

    this->chartView = new QChartView(this);

    this->hLayout->addWidget(this->swapThemeLabel);
    this->hLayout->addWidget(this->chooseChartType);
    this->hLayout->addWidget(this->swapChartTheme);
    this->hLayout->addStretch();
    this->hLayout->addWidget(this->saveAsPDF);

    this->vLayout->addLayout(this->hLayout);
    this->vLayout->addWidget(this->chartView);

}

