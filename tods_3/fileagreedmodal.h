
#ifndef FILEAGREEMODAL_H
#define FILEAGREEMODAL_H


#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QSplitter>


class FileAgreeModal : public QWidget
{
    Q_OBJECT
public:
    explicit FileAgreeModal(QWidget *parent = nullptr);
    bool getBoolIsAgreed();

signals:

public slots:
    void pressedAgree();
    void pressedDisagree();

private:
    QFrame *window;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QPushButton *agreeButton;
    QPushButton *disagreeButton;
    QLabel *textLabel;
    bool isAgreed;
};

#endif // FILEAGREEDMODAL_H
