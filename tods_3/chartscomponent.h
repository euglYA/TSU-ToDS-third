
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

class ChartsComponent : public QWidget
{
    Q_OBJECT
public:
    explicit ChartsComponent(QWidget *parent = nullptr);
    ~ChartsComponent() = default;

signals:

private:
    QChartView *chartView;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QPushButton *saveAsPDF;
    QComboBox *chooseChartType;
    QCheckBox *swapChartTheme;
};

#endif // CHARTSCOMPONENT_H
