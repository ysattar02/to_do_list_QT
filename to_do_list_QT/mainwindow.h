#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void exitApplication();
    void aboutApplication();
    void updateDateTime();

private:
    Ui::MainWindow *ui;
    QLabel *dateTimeLabel;
    QTimer *timer;
};
#endif // MAINWINDOW_H
