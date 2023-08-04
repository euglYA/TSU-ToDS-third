
#ifndef APP_H
#define APP_H


#include <QWidget>
#include <QMainWindow>

#include "filescomponent.h"

class App : public QMainWindow
{
    Q_OBJECT
public:
    explicit App(QWidget *parent = nullptr);

public slots:

signals:

private:
    FilesComponent *filesComponent;
};

#endif // APP_H
