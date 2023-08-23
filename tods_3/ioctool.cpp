#include "ioctool.h"
//#include "ioc.h"

IOCTool::IOCTool() {
    gContainer.RegisterInstance<IFileReader, NoneStrategy>();
}

std::shared_ptr<IFileReader> IOCTool::getObject() {
    return gContainer.GetObject<IFileReader>();
}

void IOCTool::changeFactoryType(QFileInfo file, int maxSize) {
    if (file.size() < 0){
        //
        //
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
        return;
    }

    QString fileExt = file.suffix();

    if (fileExt == "json"){
        qDebug() << "json";
        gContainer.RegisterFactory<IFileReader, JsonStrategy>();
    }
    else if (fileExt == "sqlite") {
        qDebug() << "sqlite";
        gContainer.RegisterFactory<IFileReader, SQLiteStrategy>();
    }
    else {
        qDebug() << "noneStr";
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
    }

}
