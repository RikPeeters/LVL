#include "aboutme.h"
#include "ui_aboutme.h"

aboutme::aboutme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutme)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/Data/Foto/Icon.png"));
    setWindowTitle("About Me");
    this->setStyleSheet("background-color: white; color: black;");

    foto.load(":/Data/Foto/TLBE.png");
    ui->Foto->setPixmap(foto.scaled(100,100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

aboutme::~aboutme()
{
    delete ui;
}

void aboutme::on_pushButton_clicked()
{
    this->close();
}

