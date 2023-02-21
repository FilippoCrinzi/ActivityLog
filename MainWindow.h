//
// Created by Filippo Crinzi on 13/02/23.
//

#ifndef MAIN_CPP_MAINWINDOW_H
#define MAIN_CPP_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "Log.h"
#include <QStringList>
#include "Date.h"
#include <QDate>
#include <QTableWidget>



class MainWindow : public QMainWindow  {
    Q_OBJECT
public:
    MainWindow(Log Register,Date day);


private:
    Log Register;
    QDate Day;
    QLabel *ViewDay;
    QTableWidget *ActivityTab;
};


#endif //MAIN_CPP_MAINWINDOW_H
