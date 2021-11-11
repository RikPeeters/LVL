#ifndef ABOUTME_H
#define ABOUTME_H

#include <QDialog>

namespace Ui {
class aboutme;
}

class aboutme : public QDialog
{
    Q_OBJECT

public:
    explicit aboutme(QWidget *parent = nullptr);
    ~aboutme();

    QPixmap foto;

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutme *ui;
};

#endif // ABOUTME_H
