
#include "chartscomponent.h"
#include <QtCharts>

ChartsComponent::ChartsComponent(QWidget *parent)
    : QWidget{parent} {

    this->vLayout = new QVBoxLayout(this);
    this->hLayout = new QHBoxLayout(this);

    this->saveAsPDF = new QPushButton("Сохранить в PDF", this);
    this->chooseChartTypeLabel = new QLabel("Выберите тип диаграммы ", this);
    this->swapChartTheme = new QCheckBox("Черно-белый график", this);
    this->chooseChartType = new QComboBox(this);
    this->chooseChartType->setFixedWidth(150);

    this->chooseChartType->addItems({"BarChart", "PieChart"});

    this->chartView = new QChartView(this);
    this->chartView->setRenderHint(QPainter::Antialiasing);

    this->_chart = chartView->chart();
    this->_chart->setTheme(QChart::ChartThemeQt);
    this->_chart->legend()->hide();
//    this->_chart->legend()->showToolTips();
    this->chartType = new BarChart;

    this->hLayout->addWidget(this->chooseChartTypeLabel);
    this->hLayout->addWidget(this->chooseChartType);
    this->hLayout->addWidget(this->swapChartTheme);
    this->hLayout->addStretch();
    this->hLayout->addWidget(this->saveAsPDF);

    this->vLayout->addLayout(this->hLayout);
    this->vLayout->addWidget(this->chartView);

}

void ChartsComponent::changeChartData(QMap<QString, QVariant> data) {
    this->_data = data;
    this->rerenderChart();
}

void ChartsComponent::rerenderChart() {
    this->_chart->removeAllSeries();
    this->_chart->addSeries(this->chartType->getSeries(_data));
    this->_chart->createDefaultAxes();
    this->chartView->show();
}

