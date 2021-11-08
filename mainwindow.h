#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QKeyEvent>
#include <QStatusBar>
#include <QDebug>

#define QD qDebug() << __FILE__ << __LINE__

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString Map = "No map selected";
    QString Agent = "No agent selected";
    QPixmap FotoMap;
    QPixmap FotoAgent;
    QPixmap Temp;
    QString filename;
    QString name;
    QString Side;
    bool keys = false;


signals:
    void enterclicked0();
    void enterclicked1();
    void enterclicked2();

private slots:
    void on_PBbind_clicked();
    void on_PBhaven_clicked();
    void on_PBsplit_clicked();
    void on_PBascent_clicked();
    void on_PBicebox_clicked();
    void on_PBbreeze_clicked();
    void on_PBbrim_clicked();
    void on_PBsova_clicked();
    void on_PBviper_clicked();
    void on_PBkill_clicked();

    void createStatusBar();

    void Continue();

    void update0();
    void update1();
    void update2();

    void on_actionExit_triggered();

    void on_actionToggle_keys_triggered();

    void on_Back_clicked();

    void on_A1_clicked();
    void on_A2_clicked();
    void on_A3_clicked();
    void on_A4_clicked();
    void on_A5_clicked();
    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();

    void on_Back2_clicked();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent*);

    int w,h;

};
#endif // MAINWINDOW_H
