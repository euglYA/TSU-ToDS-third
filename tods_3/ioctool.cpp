#include "ioctool.h"

void IOCTool::changeFactoryType(QFileInfo file, int maxSize) {
    if (file.size() > maxSize){
        //
        //
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
        return;
    }

    QString fileExt = file.suffix();

    if (fileExt == "json")
        gContainer.RegisterFactory<IFileReader, JsonStrategy>();
    else if (fileExt == "sqlite")
        gContainer.RegisterFactory<IFileReader, SQLiteStrategy>();
    else
        gContainer.RegisterFactory<IFileReader, NoneStrategy>();
}
