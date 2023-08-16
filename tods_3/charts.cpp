#include "charts.h"
#include "qbarset.h"

QAbstractSeries* PieChart::getSeries(const QMap<QString, QVariant>& data) {
    this->_series = new QPieSeries();
    QMapIterator<QString, QVariant> iterator(data);
    while (iterator.hasNext()) {
        iterator.next();
        this->_series->append(iterator.key(), iterator.value().toDouble());
    }
    return this->_series;
}

QAbstractSeries* BarChart::getSeries(const QMap<QString, QVariant>& data) {
    this->_series = new QBarSeries();
    QMapIterator<QString, QVariant> iterator(data);
    QBarSet *set = new QBarSet("");
    while (iterator.hasNext()) {
        iterator.next();
        *set << iterator.value().toDouble();
    }
    this->_series->append(set);
    return this->_series;
}
