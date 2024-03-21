#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //declaring menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    QMenu *fileMenu = menuBar->addMenu("&Actions");
    QAction *exitAction = new QAction("&Exit", this);
    fileMenu->addAction(exitAction);

    //connect statements
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
        rv = QMessageBox::information(this, "Dialog", "Exit Program?",
                                      QMessageBox::StandardButton::Ok |
                                          QMessageBox::StandardButton::No);

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

void MainWindow::updateDateTime(){
    QDateTime currDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currDateTime.toString("hh:mm || dd:mm:yyyy");
    dateTimeLabel->setText(formattedDateTime);
}
