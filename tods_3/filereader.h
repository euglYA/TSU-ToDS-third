
#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFileInfo>
#include <QList>
#include <QMap>
#include <QVariant>

class IFileReader {
public:
    virtual ~IFileReader() noexcept = default;
    virtual QMap<QString, QVariant> extractData(const QFileInfo file) = 0;

    QMap<QString, QVariant> _data;
};

class JsonStrategy: public IFileReader {
public:
    QMap<QString, QVariant> extractData(QFileInfo file) override;
};

class SQLiteStrategy: public IFileReader {
public:
    QMap<QString, QVariant> extractData(QFileInfo file) override;

};

class NoneStrategy: public IFileReader {
public:
    QMap<QString, QVariant> extractData(QFileInfo file) override { qDebug() << "extract none"; Q_UNUSED(file); return QMap<QString, QVariant>(); }
};

#endif // FILEREADER_H
