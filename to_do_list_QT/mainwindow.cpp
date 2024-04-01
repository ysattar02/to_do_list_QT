#include "mainwindow.h"
#include "ui_mainwindow.h"

//global variables
QString absoluteFilePath = "/Users/yusufsattar/Desktop/to_do_list_QT/data.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) //initializer
{
    ui->setupUi(this);
    //absoluteFilePath = getFileInfo();
    populateMap();
    populateTaskDisplay();

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
    connect(ui->completeTaskButton, &QPushButton::clicked, this, &MainWindow::completeItem);
    connect(ui->clearTaskEntryButton, &QPushButton::clicked, this, &MainWindow::clearItemInputBox);
    connect(qApp, &QCoreApplication::aboutToQuit, this, &MainWindow::writeMap);
    connect(ui->clearSelectionButton, &QPushButton::clicked, this, &MainWindow::clearSelection);

    //date/time bar
    dateTimeLabel = new QLabel(this);
    ui->statusbar->addPermanentWidget(dateTimeLabel);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDateTime);
    timer->start(1000);

    //Style Sheet Entries
    QColor green = QColor(Qt::green);
    QColor blue = QColor(Qt::blue);
    QColor red = QColor(Qt::red);
    QColor black = QColor(Qt::black);
    QColor darkPurple(72, 28, 94);

    //changing background color of central application
    ui->centralwidget->setAutoFillBackground(true);
    QPalette paletteOne = QPalette();
    paletteOne.setColor(QPalette::Window, darkPurple);
    ui->centralwidget->setPalette(paletteOne);

    //changing color palette for the task entry widget
    ui->taskEntry->setAutoFillBackground(true);
    QPalette paletteTwo = QPalette();
    paletteTwo.setColor(QPalette::Window, green);
    ui->taskEntry->setPalette(paletteTwo);

    //changing color palette for the task entry widget
    ui->taskDisplay->setAutoFillBackground(true);
    QPalette paletteThree = QPalette();
    paletteThree.setColor(QPalette::Window, green);
    ui->taskDisplay->setPalette(paletteThree);

    //changing background of calendar widget
    ui->calendarWidget->setAutoFillBackground(true);
    QPalette paletteFour = QPalette();
    paletteFour.setColor(QPalette::Window, green);
    ui->calendarWidget->setPalette(paletteFour);
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
                                      "Version 1.0_5\n");
}

void MainWindow::updateDateTime(){
    QDateTime currDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currDateTime.toString("hh:mm || dd:mm:yyyy");
    dateTimeLabel->setText(formattedDateTime);
}

void MainWindow::populateMap(){
    std::cout << "Populate Function Reached\n";
    QFile dataFile(absoluteFilePath);
    //QFile dataFile("data.txt");
    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "Data File Failed to Open" << std::endl;
        return;
    }
    QTextStream in(&dataFile);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2){
            int key = parts[0].trimmed().toInt();
            if (key == 1){
                QString value = parts[1].trimmed();
                items.insert({key, value.toStdString()});
            }
        }
    }
    dataFile.close();
    populateTaskDisplay();
}

void MainWindow::addItem(){
    QString taskDescription = ui->taskEntry->text();
    if (taskDescription.isEmpty()){
        QMessageBox::warning(this, "Empty Task", "Empty Task Cannot Be Added");
        return;
    }
    ui->taskEntry->clear();
    //QMessageBox::information(this, "Entered Text", "You Entered: " + taskDescription);
    std::string temp = taskDescription.toStdString();
    items.insert(std::make_pair(1, temp));
    populateTaskDisplay();
}

void MainWindow::populateTaskDisplay(){
    ui->taskDisplay->clear();
    for (const auto& pair:items){
        if (pair.first == 1){
            QString key = QString::number(pair.first);
            QString value = QString::fromStdString(pair.second);
            QString itemText = key + ": " + value;
            QListWidgetItem *item = new QListWidgetItem(itemText);
            ui->taskDisplay->addItem(item);
        }
    }
}

void MainWindow::completeItem() {
    QMessageBox::StandardButton rv = QMessageBox::StandardButton::Ok;
    rv = QMessageBox::information(this, "Dialog", "Complete Item?", QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::No);
    if (rv == QMessageBox::StandardButton::Ok){
        QListWidgetItem* selectedItem = ui->taskDisplay->currentItem();
        if (!selectedItem){
            QMessageBox::warning(this, "No Task Selected", "Empty Task Cannot Be Completed");
            return;
        }
        QString selectedItemText = selectedItem->text();
        QString taskDescription = selectedItemText.split(":").at(1).trimmed();
        auto range = items.equal_range(1);
        for (auto it = range.first; it != range.second; ++it){
            if (it->second == taskDescription.toStdString()){
                items.insert({0, it->second});
                it = items.erase(it);
                break;
            }
        }
        populateTaskDisplay();
        return;
    }
    else if (rv == QMessageBox::StandardButton::No){
        return;
        populateTaskDisplay();
    }
    else{
        return;
    }
    // QListWidgetItem* selectedItem = ui->taskDisplay->currentItem();
    // if (!selectedItem){
    //     QMessageBox::warning(this, "No Task Selected", "Empty Task Cannot Be Completed");
    //     return;
    // }
    // QString selectedItemText = selectedItem->text();
    // QString taskDescription = selectedItemText.split(":").at(1).trimmed();
    // auto range = items.equal_range(1);
    // for (auto it = range.first; it != range.second; ++it){
    //     if (it->second == taskDescription.toStdString()){
    //         items.insert({0, it->second});
    //         it = items.erase(it);
    //         break;
    //     }
    // }
    // populateTaskDisplay();
}

void MainWindow::clearItemInputBox(){
    ui->taskEntry->clear();
    std::cout << "Cleared Input Box" << std::endl;
}

void MainWindow::writeMap(){
    QFile dataFile(absoluteFilePath);
    //QFile dataFile("data.txt");
    if (!dataFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        std::cout << "Data File Failed to Open" << std::endl;
        return;
    }
    QTextStream out(&dataFile);
    for (auto it = items.begin(); it != items.end(); ++it){
        out << it->first << ": " << QString::fromStdString(it->second) << "\n";
    }
    dataFile.close();
}

QString MainWindow::getFileInfo(){
    QFile dataFile("data.txt");
    if (dataFile.exists()){
        std::cout << "File Exists" << std::endl;
    }
    else{
        dataFile.open(QIODevice::WriteOnly);
        dataFile.close();
        std::cout << "File Created Successfully" << std::endl;
    }
    QFileInfo infoOne("data.txt");
    QString temp = infoOne.absoluteFilePath();
    std::cout << "File Path Absolute: " << temp.toStdString() << std::endl;
    return temp;
}

void MainWindow::clearSelection(){
    ui->taskDisplay->clearSelection();
}
