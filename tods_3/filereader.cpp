
#include "filereader.h"
#include "qjsonarray.h"
#include "qjsonobject.h"

#include <QJsonDocument>

bool JsonStrategy::extractData(const QFileInfo fileInfo) {
    QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QString jsonString;
    jsonString = file.readAll();
    file.close();

    auto jsonData = QJsonDocument::fromJson(jsonString.toUtf8());

    QJsonArray jsonArray = jsonData.array();
    QJsonValue value;
    QString key;
    QMap<QString, QVariant> mapFromFile;

    for (auto jsonObject : jsonArray) {
        value = jsonObject.toObject().value("Time");
        key = value.toString();

        value = jsonObject.toObject().value("Value");
        mapFromFile[key] = value;
    }


    this->_data = mapFromFile;
    return true;
}

bool SQLiteStrategy::extractData(const QFileInfo file) {

}
