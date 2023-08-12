
#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFileInfo>
#include <QList>


class IFileReader {
public:
    virtual ~IFileReader() noexcept = default;
    virtual bool extractData(const QFileInfo file) = 0;

    QMap<QString, QVariant> _data;
};

class JsonStrategy: public IFileReader {
public:
    bool extractData(const QFileInfo file) override;
};

class SQLiteStrategy: public IFileReader {
public:
    bool extractData(const QFileInfo file) override;

};

class NoneStrategy: public IFileReader {
public:
    bool extractData(const QFileInfo file) override { return false; }
};

#endif // FILEREADER_H
