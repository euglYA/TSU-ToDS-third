
#include "chartscomponent.h"
#include <QtCharts>

ChartsComponent::ChartsComponent(QWidget *parent)
    : QWidget{parent} {

    this->vLayout = new QVBoxLayout(this);
    this->hLayout = new QHBoxLayout(this);

    this->saveAsPDF = new QPushButton("Сохранить в PDF", this);
    this->saveAsPDF->setEnabled(false);

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
    this->chartType = new BarChart;

    this->hLayout->addWidget(this->chooseChartTypeLabel);
    this->hLayout->addWidget(this->chooseChartType);
    this->hLayout->addWidget(this->swapChartTheme);
    this->hLayout->addStretch();
    this->hLayout->addWidget(this->saveAsPDF);

    this->vLayout->addLayout(this->hLayout);
    this->vLayout->addWidget(this->chartView);

    QObject::connect(this->chooseChartType, &QComboBox::currentTextChanged, this, &ChartsComponent::changeChartType);
    QObject::connect(this->swapChartTheme, &QCheckBox::stateChanged, this, &ChartsComponent::swapBlackAndWhiteTheme);
    QObject::connect(this->saveAsPDF, &QPushButton::clicked, this, &ChartsComponent::saveChartAsPdf);
}

void ChartsComponent::changeChartType(const QString &text) {
    if (text == this->chartType->getType())
        return;

    if (text == "BarChart")
        this->chartType = new BarChart;
    else if (text == "PieChart")
        this->chartType = new PieChart;
    else
        return;

    this->rerenderChart();
}

void ChartsComponent::changeChartData(QMap<QString, QVariant> data) {
    this->_data = data;
    this->rerenderChart();
    this->saveAsPDF->setEnabled(true);
}

void ChartsComponent::swapBlackAndWhiteTheme(bool state) {
    if (state)
        this->_chart->setTheme(QChart::ChartThemeHighContrast);
    else
        this->_chart->setTheme(QChart::ChartThemeQt);
}

void ChartsComponent::saveChartAsPdf() {
    if (this->_data.size() == 0) {
        return;
    }

    QString dir = QFileDialog::getSaveFileName(this, "Save chart as PDF", QDir::homePath(), "PDF files (*.pdf)");

    QPdfWriter writer(dir);
    writer.setCreator("euglYA");
    writer.setPageSize(QPageSize::A4);
    QPainter painter(&writer);
    this->chartView->render(&painter);
    painter.end();
}

void ChartsComponent::rerenderChart() {
    this->_chart->removeAllSeries();
    this->_chart->addSeries(this->chartType->getSeries(_data));
    this->_chart->createDefaultAxes();
    this->chartView->show();
}

