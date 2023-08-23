
#include "filereader.h"
#include "qjsonarray.h"
#include "qjsonobject.h"

#include <QJsonDocument>

QMap<QString, QVariant> JsonStrategy::extractData(QFileInfo fileInfo) {
    QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::ReadOnly)) {
        return QMap<QString, QVariant>();
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

//    this->_data = mapFromFile;
    return mapFromFile;
}

QMap<QString, QVariant> SQLiteStrategy::extractData(QFileInfo file) {
    qDebug() << "extract sql";
    Q_UNUSED(file);
    return QMap<QString, QVariant>();
}
