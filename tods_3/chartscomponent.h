
#ifndef CHARTSCOMPONENT_H
#define CHARTSCOMPONENT_H


#include <QWidget>
#include <QtCharts/QtCharts>


class ChartsComponent : public QWidget
{
    Q_OBJECT
public:
    explicit ChartsComponent(QWidget *parent = nullptr);
    ~ChartsComponent() = default;

signals:

};

#endif // CHARTSCOMPONENT_H
