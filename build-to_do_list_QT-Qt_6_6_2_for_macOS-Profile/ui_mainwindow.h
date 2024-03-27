/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *taskDisplay;
    QLineEdit *taskEntry;
    QPushButton *addTaskButton;
    QPushButton *completeTaskButton;
    QPushButton *clearTaskEntryButton;
    QCalendarWidget *calendarWidget;
    QLabel *textLabelOne;
    QPushButton *clearSelectionButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuActions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        taskDisplay = new QListWidget(centralwidget);
        taskDisplay->setObjectName("taskDisplay");
        taskDisplay->setGeometry(QRect(0, 220, 801, 281));
        taskEntry = new QLineEdit(centralwidget);
        taskEntry->setObjectName("taskEntry");
        taskEntry->setGeometry(QRect(10, 30, 271, 71));
        addTaskButton = new QPushButton(centralwidget);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setGeometry(QRect(60, 100, 81, 32));
        completeTaskButton = new QPushButton(centralwidget);
        completeTaskButton->setObjectName("completeTaskButton");
        completeTaskButton->setGeometry(QRect(280, 500, 101, 32));
        clearTaskEntryButton = new QPushButton(centralwidget);
        clearTaskEntryButton->setObjectName("clearTaskEntryButton");
        clearTaskEntryButton->setGeometry(QRect(150, 100, 81, 32));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(530, 10, 251, 181));
        textLabelOne = new QLabel(centralwidget);
        textLabelOne->setObjectName("textLabelOne");
        textLabelOne->setGeometry(QRect(100, 10, 91, 16));
        clearSelectionButton = new QPushButton(centralwidget);
        clearSelectionButton->setObjectName("clearSelectionButton");
        clearSelectionButton->setGeometry(QRect(390, 500, 101, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 195, 91, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName("menuActions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuActions->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addTaskButton->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        completeTaskButton->setText(QCoreApplication::translate("MainWindow", "Complete Task", nullptr));
        clearTaskEntryButton->setText(QCoreApplication::translate("MainWindow", "Clear Box", nullptr));
        textLabelOne->setText(QCoreApplication::translate("MainWindow", "Task Creation", nullptr));
        clearSelectionButton->setText(QCoreApplication::translate("MainWindow", "Clear Selection", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current Tasks", nullptr));
        menuActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
