
#ifndef IOCTOOL_H
#define IOCTOOL_H

#include "filereader.h"
#include "ioc.h"

class IOCTool {
public:
    IOCTool() {
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
    }

    std::shared_ptr<IFileReader> getObject() {
        return gContainer.GetObject<IFileReader>();
    }

public slots:
    void changeFactoryType(QFileInfo file, int maxSize);
};

#endif // IOCTOOL_H
