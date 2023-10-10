
#ifndef APP_H
#define APP_H


#include <QWidget>
#include <QMainWindow>
#include <QMap>

#include "chartscomponent.h"
#include "filescomponent.h"
#include "ioctool.h"

class App : public QMainWindow
{
    Q_OBJECT
private:
    void returnMessageBox(QString text, QString secText);

public:
    explicit App(QWidget *parent = nullptr);

public slots:
    void chartDataChanger(QFileInfo selectedFile);

signals:
    void updateFactoryType(QFileInfo selectedFile);
    void updateChartData(QMap<QString, QVariant> data);

private:
    FilesComponent *filesComponent;
    ChartsComponent *chartsComponent;
    IOCTool *iocTool;
};

#endif // APP_H
