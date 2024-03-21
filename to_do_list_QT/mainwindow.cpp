#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) //initializer
{
    ui->setupUi(this);

    //declaring menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    QMenu *fileMenu = menuBar->addMenu("&Actions");
    QAction *exitAction = new QAction("&Exit", this);
    QAction *aboutAction = new QAction("&About", this);
    fileMenu->addAction(aboutAction);
    fileMenu->addAction(exitAction);

    //connect statement for menu actions
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutApplication);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApplication);

    //date/time bar
    dateTimeLabel = new QLabel(this);
    ui->statusbar->addPermanentWidget(dateTimeLabel);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDateTime);
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitApplication(){
    QMessageBox::StandardButton rv = QMessageBox::StandardButton::Ok;
    do {
        rv = QMessageBox::information(this, "Dialog", "Exit Program?", QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::No);
        switch(rv) {
        case QMessageBox::StandardButton::Ok:
            printf("You clicked Ok\n");
            QApplication::quit();
            fflush(stdout);
            return;
        case QMessageBox::StandardButton::No:
            printf("You clicked No\n");
            fflush(stdout);
            return;
        default:
            break;
        }
    } while(true);
}

void MainWindow::aboutApplication(){
    QMessageBox::about(this, "About", "App Name: To Do List\n"
                                      "Author: Yusuf S.\n"
                                      "Version 1.0_2\n");
}

void MainWindow::updateDateTime(){
    QDateTime currDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currDateTime.toString("hh:mm || dd:mm:yyyy");
    dateTimeLabel->setText(formattedDateTime);
}
