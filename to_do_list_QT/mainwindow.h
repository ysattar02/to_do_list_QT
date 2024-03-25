#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QInputDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QVBoxLayout>
#include <QFile>
#include <QFileInfo>
#include <iostream>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//global variables
extern QString absoluteFilePath;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getFileInfo();

private slots:
    void exitApplication();
    void aboutApplication();
    void updateDateTime();
    void populateMap();
    void addItem(); //takes in item from text box
    void populateTaskDisplay(); //adds inputted item to the map and displays it
    void completeItem(); //marks item as complete
    void clearItemInputBox();
    void writeMap();

private:
    Ui::MainWindow *ui;
    QLabel *dateTimeLabel;
    QTimer *timer;
    std::multimap<int, std::string> items;
};
#endif // MAINWINDOW_H
