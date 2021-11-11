#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createStatusBar();
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->Continue, SIGNAL(clicked()), this, SLOT(Continue()));
    connect(this, SIGNAL(enterclicked0()), this, SLOT(Continue()));
    connect(this, SIGNAL(enterclicked1()), this, SLOT(on_Back_clicked()));
    //connect(this, SIGNAL(enterclicked2()), this, SLOT(on_Back2_clicked()));

    setWindowIcon(QIcon(":/Data/Foto/Icon.png"));
    setWindowTitle("Liquid Valorant Lineups");
    this->setStyleSheet("background-color: lightblue; color: black;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//input
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_1)
    {
        statusBar()->showMessage(tr("Key: 1"));

        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Bind";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_2)
    {
        statusBar()->showMessage(tr("Key: 2"));

        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Haven";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_3)
    {
        statusBar()->showMessage(tr("Key: 3"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Split";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_4)
    {
        statusBar()->showMessage(tr("Key: 4"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Ascent";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_5)
    {
        statusBar()->showMessage(tr("Key: 5"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Icebox";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_6)
    {
        statusBar()->showMessage(tr("Key: 6"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Map = "Breeze";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_7)
    {
        statusBar()->showMessage(tr("Key: 7"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
                Agent = "Brimstone";
                update0();
                break;
        }
    }
    if(event->key() == Qt::Key_8)
    {
        statusBar()->showMessage(tr("Key: 8"));
        Agent = "Viper";
        update0();
    }
    if(event->key() == Qt::Key_9)
    {
        statusBar()->showMessage(tr("Key: 9"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            Agent = "Killjoy";
            update0();
            break;
        }
    }
    if(event->key() == Qt::Key_Enter)
    {
        statusBar()->showMessage(tr("Key: Enter"));
        switch (ui->stackedWidget->currentIndex()) {
        case 0:
            emit enterclicked0();
            break;
        case 1:
            emit enterclicked1();
            break;
        case 2:
            emit enterclicked2();
            break;

        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3 || event->key() == Qt::Key_4
    || event->key() == Qt::Key_5 || event->key() == Qt::Key_6 || event->key() == Qt::Key_7 || event->key() == Qt::Key_8
    || event->key() == Qt::Key_9 || event->key() == Qt::Key_0 || event->key() == Qt::Key_Enter)
    {
        statusBar()->showMessage(tr("Running"));
    }
}

//resizeevent
void MainWindow::resizeEvent(QResizeEvent*){
    update0();
    update1();
    update2();
}


//create statusbar
void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Running"));
}

void MainWindow::showx(int a, int b){
    if(a > 0){
        ui->A1->show();
        ui->AF1->show();
    }if(a > 1){
        ui->A2->show();
        ui->AF2->show();
    }if(a > 2){
        ui->A3->show();
        ui->AF3->show();
    }if(a > 3){
        ui->A4->show();
        ui->AF4->show();
    }if(a > 4){
        ui->A5->show();
        ui->AF5->show();
    }
    if(b > 0){
        ui->B1->show();
        ui->BF1->show();
    }if(b > 1){
        ui->B2->show();
        ui->BF2->show();
    }if(b > 2){
        ui->B3->show();
        ui->BF3->show();
    }if(b > 3){
        ui->B4->show();
        ui->BF4->show();
    }if(b > 4){
        ui->B5->show();
        ui->BF5->show();
    }
}

void MainWindow::tmpl(){
    Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.png");
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.JPG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.PNG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.jpg");
    }
}

void MainWindow::hidex(){
    ui->A1->hide();
    ui->A2->hide();
    ui->A3->hide();
    ui->A4->hide();
    ui->A5->hide();
    ui->AF1->hide();
    ui->AF2->hide();
    ui->AF3->hide();
    ui->AF4->hide();
    ui->AF5->hide();
    ui->B1->hide();
    ui->B2->hide();
    ui->B3->hide();
    ui->B4->hide();
    ui->B5->hide();
    ui->BF1->hide();
    ui->BF2->hide();
    ui->BF3->hide();
    ui->BF4->hide();
    ui->BF5->hide();
}


/////////////begin index 0


//update function
void MainWindow::update0(){

    if(Map != "No map selected")
    {
        ui->labelMap->setText(Map);
        FotoMap.load(":/Data/Foto/" + Map + ".png");
        ui->FotoMap->setPixmap(FotoMap.scaled(ui->FotoMap->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
        ui->labelMap->setStyleSheet("color: black;");

    }

    if(Agent != "No agent selected")
    {
        ui->labelAgent->setText(Agent);
        FotoAgent.load(":/Data/Foto/" + Agent + ".png");
        ui->FotoAgent->setPixmap(FotoAgent.scaled(ui->FotoAgent->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
        ui->labelAgent->setStyleSheet("color: black;");
    }
}

//continue
void MainWindow::Continue()
{

    if (Agent != "No agent selected" && Map != "No map selected")
    {
        ui->stackedWidget->setCurrentIndex(1);
        update1();
    }else{
        if(Map == "No map selected")
        {
        ui->labelMap->setStyleSheet("color: red;");
        }
        if(Agent == "No agent selected")
        {
        ui->labelAgent->setStyleSheet("color: red;");
        }
    }
}

//map and agent buttons
void MainWindow::on_PBbind_clicked()
{
    Map = "Bind";
    update0();
}
void MainWindow::on_PBhaven_clicked()
{
    Map = "Haven";
    update0();
}
void MainWindow::on_PBsplit_clicked()
{
    Map = "Split";
    update0();
}
void MainWindow::on_PBascent_clicked()
{
    Map = "Ascent";
    update0();
}
void MainWindow::on_PBicebox_clicked()
{
    Map = "Icebox";
    update0();
}
void MainWindow::on_PBbreeze_clicked()
{
    Map = "Breeze";
    update0();
}
void MainWindow::on_PBbrim_clicked()
{
    Agent = "Brimstone";
    update0();
}

void MainWindow::on_PBviper_clicked()
{
    Agent = "Viper";
    update0();
}
void MainWindow::on_PBkill_clicked()
{
    Agent = "Killjoy";
    update0();
}


/////////////end index 0

/////////////begin index 1


void MainWindow::update1(){

    //update top balk
    ui->Selected->setText("Map: " + Map + "  Agent: " + Agent);
    FotoMap.load(":/Data/Foto/" + Map + ".png");
    ui->FotoA->setPixmap(FotoMap.scaled(ui->FotoA->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
    FotoAgent.load(":/Data/Foto/" + Agent + ".png");
    ui->FotoB->setPixmap(FotoAgent.scaled(ui->FotoB->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
    if(Map == "Haven"){
        ui->groupBox_4->setTitle("B AND C Bomside");
    }else{
        ui->groupBox_4->setTitle("B Bomside");
    }



    //hide every box
    hidex();

    //Agent ---- maps
    if(Agent == "Brimstone")
    {
        if(Map == "Bind")
        {
            showx(2,2);

            //A1
            name = "Box";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Default";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Def";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        }
        if(Map == "Haven")
        {
            showx(2,2);

        //A1
        name = "Default";
        Side = "A";
        ui->A1->setText(name);
        tmpl();
        ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        //A2
        name = "Short";
        Side = "A";
        ui->A2->setText(name);
        tmpl();
        ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        //B1
        name = "Middle";
        Side = "B";
        ui->B1->setText(name);
        tmpl();
        ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        //C1
        name = "Box";
        Side = "B";
        ui->B2->setText(name);
        tmpl();
        ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        }
        if(Map == "Split")
        {
            showx(2,1);

            //A1
            name = "Back";
            Side = "A";;
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Default";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Ascent")
        {
            showx(1,3);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Market";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B3
            name = "Def";
            Side = "B";
            ui->B3->setText(name);
            tmpl();
            ui->BF3->setPixmap(Temp.scaled(ui->BF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Icebox")
        {
            showx(1,1);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Breeze")
        {
            showx(1,1);

            //A1
            name = "Edge";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Corner";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {

        }
    }
    if(Agent == "Viper")
    {
        if(Map == "Bind")
        {
            showx(3,3);

            //A1
            name = "Box";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Lamps1";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A3
            name = "Lamps2";
            Side = "A";
            ui->A3->setText(name);
            tmpl();
            ui->AF3->setPixmap(Temp.scaled(ui->AF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Left1";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Left2";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B3
            name = "Left3";
            Side = "B";
            ui->B3->setText(name);
            tmpl();
            ui->BF3->setPixmap(Temp.scaled(ui->BF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        }
        if(Map == "Haven")
        {
            showx(2,3);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Short";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Middle";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //C1
            name = "Box";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //C2
            name = "Long";
            Side = "B";
            ui->B3->setText(name);
            tmpl();
            ui->BF3->setPixmap(Temp.scaled(ui->BF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Split")
        {
            showx(4,2);

            //A1
            name = "Back1";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Back2";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A3
            name = "Back3";
            Side = "A";
            ui->A3->setText(name);
            tmpl();
            ui->AF3->setPixmap(Temp.scaled(ui->AF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A4
            name = "Default1";
            Side = "A";
            ui->A4->setText(name);
            tmpl();
            ui->AF4->setPixmap(Temp.scaled(ui->AF4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A4
            name = "Default2";
            Side = "A";
            ui->A5->setText(name);
            tmpl();
            ui->AF5->setPixmap(Temp.scaled(ui->AF5->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default1";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Default2";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Ascent")
        {
            showx(4,4);

            //A1
            name = "Box1";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Box2";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A3
            name = "Default1";
            Side = "A";
            ui->A3->setText(name);
            tmpl();
            ui->AF3->setPixmap(Temp.scaled(ui->AF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A4
            name = "Default2";
            Side = "A";
            ui->A4->setText(name);
            tmpl();
            ui->AF4->setPixmap(Temp.scaled(ui->AF4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default1";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Default2";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B3
            name = "Default3";
            Side = "B";
            ui->B3->setText(name);
            tmpl();
            ui->BF3->setPixmap(Temp.scaled(ui->BF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B4
            name = "Default4";
            Side = "B";
            ui->B4->setText(name);
            tmpl();
            ui->BF4->setPixmap(Temp.scaled(ui->BF4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Icebox")
        {
            showx(1,1);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Breeze")
        {
            showx(5,5);

            //A1
            name = "Between";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Corner";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A3
            name = "Edge";
            Side = "A";
            ui->A3->setText(name);
            tmpl();
            ui->AF3->setPixmap(Temp.scaled(ui->AF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A4
            name = "CornerMid";
            Side = "A";
            ui->A4->setText(name);
            tmpl();
            ui->AF4->setPixmap(Temp.scaled(ui->AF4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A5
            name = "EdgeMid";
            Side = "A";
            ui->A5->setText(name);
            tmpl();
            ui->AF5->setPixmap(Temp.scaled(ui->AF5->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B2
            name = "Tower";
            Side = "B";
            ui->B2->setText(name);
            tmpl();
            ui->BF2->setPixmap(Temp.scaled(ui->BF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B3
            name = "DefaultMid";
            Side = "B";
            ui->B3->setText(name);
            tmpl();
            ui->BF3->setPixmap(Temp.scaled(ui->BF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B4
            name = "TowerMid";
            Side = "B";
            ui->B4->setText(name);
            tmpl();
            ui->BF4->setPixmap(Temp.scaled(ui->BF4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B5
            name = "DefaultBox";
            Side = "B";
            ui->B5->setText(name);
            tmpl();
            ui->BF5->setPixmap(Temp.scaled(ui->BF5->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        else
        {

        }
    }
    if(Agent == "Killjoy")
    {
        if(Map == "Bind")
        {
            showx(2,1);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Box";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Haven")
        {
            showx(2, 0);

            //A1
            name = "Short";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Long";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Split")
        {
            showx(2,0);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Ramp";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Ascent")
        {
            showx(3,1);

            //A1
            name = "Default";
            Side = "A";
            ui->A1->setText(name);
            tmpl();
            ui->AF1->setPixmap(Temp.scaled(ui->AF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A2
            name = "Default2";
            Side = "A";
            ui->A2->setText(name);
            tmpl();
            ui->AF2->setPixmap(Temp.scaled(ui->AF2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //A3
            name = "Box";
            Side = "A";
            ui->A3->setText(name);
            tmpl();
            ui->AF3->setPixmap(Temp.scaled(ui->AF3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            //B1
            name = "Default";
            Side = "B";
            ui->B1->setText(name);
            tmpl();
            ui->BF1->setPixmap(Temp.scaled(ui->BF1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        if(Map == "Icebox")
        {
            //no viable lineups
        }
        if(Map == "Breeze")
        {
            //no viable lineups
        }
        else
        {

        }
    }
    else
    {

    }


}

//back
void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update0();
}

//bottons
void MainWindow::on_A1_clicked()
{
    Side = "A";
    name = ui->A1->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_A2_clicked()
{
    Side = "A";
    name = ui->A2->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_A3_clicked()
{
    Side = "A";
    name = ui->A3->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_A4_clicked()
{
    Side = "A";
    name = ui->A4->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_A5_clicked()
{
    Side = "A";
    name = ui->A5->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_B1_clicked()
{
    Side = "B";
    name = ui->B1->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_B2_clicked()
{
    Side = "B";
    name = ui->B2->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_B3_clicked()
{
    Side = "B";
    name = ui->B3->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_B4_clicked()
{
    Side = "B";
    name = ui->B4->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
void MainWindow::on_B5_clicked()
{
    Side = "B";
    name = ui->B5->text();
    ui->stackedWidget->setCurrentIndex(2);
    update2();
    QD << name;
}
/////////////end index 1

/////////////begin index 2

void MainWindow::update2()
{
    Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Bom.png");
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Bom.JPG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Bom.PNG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Bom.jpg");
    }
    ui->Bom->setPixmap(Temp.scaled(ui->Bom->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.png");
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.JPG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.PNG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Pos.jpg");
    }
    ui->Pos->setPixmap(Temp.scaled(ui->Pos->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Shot.png");
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Shot.JPG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Shot.PNG");
    }
    if(Temp.isNull()){
            Temp.load(":/Data/Foto/" + Agent + "/" + Map + "/" + Side + name + "Shot.jpg");
    }
    ui->Shot->setPixmap(Temp.scaled(ui->Shot->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_Back2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    update1();
}



/////////////end index 2

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//toggles the keys
void MainWindow::on_actionToggle_keys_triggered()
{
    if(keys == false){
        //index0
        ui->PBbind->setText("Bind (1)");
        ui->PBhaven->setText("Haven (2)");
        ui->PBsplit->setText("Split (3)");
        ui->PBascent->setText("Ascent (4)");
        ui->PBicebox->setText("Icebox 5)");
        ui->PBbreeze->setText("Breeze (6)");
        ui->PBbrim->setText("Brimstone (7)");
        ui->PBviper->setText("Viper (8)");
        ui->PBkill->setText("Killjoy (9)");
        ui->Continue->setText("Show lineups (Enter)");

        //index1
        ui->Back->setText("Back (Enter)");

        keys = true;
    }else if(keys == true){
        //index0
        ui->PBbind->setText("Bind");
        ui->PBhaven->setText("Haven");
        ui->PBsplit->setText("Split");
        ui->PBascent->setText("Ascent");
        ui->PBicebox->setText("Icebox");
        ui->PBbreeze->setText("Breeze");
        ui->PBbrim->setText("Brimstone");
        ui->PBviper->setText("Viper");
        ui->PBkill->setText("Killjoy");
        ui->Continue->setText("Show lineups");

        //index1
        ui->Back->setText("Back");

        keys = false;
    }else{
        statusBar()->showMessage(tr("Error!!"));
    }
}



void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionAbout_Me_triggered()
{
    am->show();
}

