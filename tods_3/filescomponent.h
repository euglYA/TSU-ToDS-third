
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
#include <QFileDialog>

class FilesComponent : public QListWidget
{
    Q_OBJECT
public:
    explicit FilesComponent(QWidget *parent = nullptr);
    ~FilesComponent() = default;
    QItemSelectionModel *selectionModel;

signals:
    void fileSelected(QFileInfo selectedFile);

public slots:
    void onClickedChooseDirectory();
    void onClickedFile(const QModelIndex& selectedFile);

private:
    QPushButton *chooseDirectoryButton;
    QFileSystemModel *fsModel;
    QTableView *tableView;
    QVBoxLayout *vLayout;
    QLabel *pathLabel;
};

#endif // FILESCOMPONENT_H
