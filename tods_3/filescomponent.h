
#ifndef FILESCOMPONENT_H
#define FILESCOMPONENT_H


#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

class FilesComponent : public QListWidget
{
    Q_OBJECT
public:
    explicit FilesComponent(QWidget *parent = nullptr);
    ~FilesComponent() = default;

signals:

private:
    QPushButton *chooseDirectoryButton;
    QFileSystemModel *fsModel;
    QTableView *tableView;
    QVBoxLayout *boxLayout;
    QLabel *pathLabel;
};

#endif // FILESCOMPONENT_H
