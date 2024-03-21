#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) //initializer
{
    ui->setupUi(this);
    populateMap();
    populateTaskDisplay();

    //creating widget for text entry


    //declaring menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    QMenu *fileMenu = menuBar->addMenu("&Actions");
    QAction *exitAction = new QAction("&Exit", this);
    QAction *aboutAction = new QAction("&About", this);
    fileMenu->addAction(aboutAction);
    fileMenu->addAction(exitAction);

    //connect statement for menu actions and buttons
    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutApplication);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApplication);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addItem);

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
    do{
        rv = QMessageBox::information(this, "Dialog", "Exit Program?", QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::No);
        switch(rv){
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
    QMessageBox::information(this, "About", "App Name: To Do List\n"
                                      "Author: Yusuf S.\n"
                                      "Version 1.0_3\n");
}

void MainWindow::updateDateTime(){
    QDateTime currDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currDateTime.toString("hh:mm || dd:mm:yyyy");
    dateTimeLabel->setText(formattedDateTime);
}

void MainWindow::populateMap(){
    std::cout << "Populate Function Reached\n";
    QFile dataFile("/Users/yusufsattar/Desktop/to_do_list_QT/to_do_list_QT/data.txt");
    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "Data File Failed to Open" << std::endl;
        return;
    }
    while (!dataFile.atEnd()){
        QByteArray currLine = dataFile.readLine();
        std::cout << "Current Line: " << currLine.constData() << std::endl;
    }
}

void MainWindow::addItem(){
    QString taskDescription = ui->lineEdit->text();
    if (taskDescription.isEmpty()){
        QMessageBox::warning(this, "Empty Task", "Empty Task Cannot Be Added");
        return;
    }
    ui->lineEdit->clear();
    QMessageBox::information(this, "Entered Text", "You Entered: " + taskDescription);
    std::string temp = taskDescription.toStdString();
    items.insert(std::make_pair(1, temp));
    populateTaskDisplay();
}

void MainWindow::populateTaskDisplay(){
    ui->taskDisplay->clear();
    for (const auto& pair:items){
        QString key = QString::number(pair.first);
        QString value = QString::fromStdString(pair.second);
        QString itemText = key + ": " + value;
        QListWidgetItem *item = new QListWidgetItem(itemText);
        ui->taskDisplay->addItem(item);
    }
}

/*
 * To Do
 * Figure out Key Isssue
*/
