#ifndef CHARTSCOMPONENT_H
#define CHARTSCOMPONENT_H

#include <QWidget>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>

#include "charts.h"


class ChartsComponent : public QWidget
{
    Q_OBJECT
public:
    explicit ChartsComponent(QWidget *parent = nullptr);
    ~ChartsComponent() = default;
    void rerenderChart();

public slots:
    void changeChartData(QMap<QString, QVariant> data);
    void changeChartType(const QString &text);
    void swapBlackAndWhiteTheme(bool state);
    void saveChartAsPdf();

private:
    IChart *chartType;
    QMap<QString, QVariant> _data;

    QChart *_chart;
    QChartView *chartView;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QPushButton *saveAsPDF;
    QComboBox *chooseChartType;
    QCheckBox *swapChartTheme;
    QLabel *chooseChartTypeLabel;

};

#endif // CHARTSCOMPONENT_H
