
#ifndef IOCTOOL_H
#define IOCTOOL_H

#include <QObject>

#include "filereader.h"
#include "ioc.h"

class IOCTool: public QObject {
    Q_OBJECT
public:
    IOCTool();

    std::shared_ptr<IFileReader> getObject();

public slots:
    void changeFactoryType(QFileInfo file, int maxSize);
};

#endif // IOCTOOL_H
