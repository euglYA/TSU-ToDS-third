#include "ioctool.h"
//#include "ioc.h"

IOCTool::IOCTool() {
    gContainer.RegisterInstance<IFileReader, NoneStrategy>();
}

std::shared_ptr<IFileReader> IOCTool::getObject() {
    return gContainer.GetObject<IFileReader>();
}

void IOCTool::changeFactoryType(QFileInfo file) {
    QString fileExt = file.suffix();

    if (fileExt == "json"){
        gContainer.RegisterFactory<IFileReader, JsonStrategy>();
    }
    else if (fileExt == "sqlite") {
        gContainer.RegisterFactory<IFileReader, SQLiteStrategy>();
    }
    else {
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
    }

}
