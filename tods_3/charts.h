
#ifndef CHARTS_H
#define CHARTS_H

#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QAbstractSeries>



class IChart {
public:
    IChart() = default;
    virtual ~IChart() = default;
    virtual QAbstractSeries* getSeries(const QMap<QString, QVariant>& data) = 0;
    virtual QString getType() = 0;
};

class PieChart : public IChart {
public:
    PieChart() = default;
    ~PieChart() override { delete _series; }
    QAbstractSeries* getSeries(const QMap<QString, QVariant>& data) override;
    QString getType() override {
        return "PieChart";
    }
private:
    QPieSeries* _series;
};



class BarChart : public IChart {
public:
    BarChart() = default;
    ~BarChart() override { delete _series; }
    QAbstractSeries* getSeries(const QMap<QString, QVariant>& data) override;
    QString getType() override {
        return "BarChart";
    }
private:
    QBarSeries* _series;
};

#endif // CHARTS_H
