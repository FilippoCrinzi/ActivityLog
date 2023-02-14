//
// Created by Filippo Crinzi on 13/02/23.
//

#ifndef MAIN_CPP_MAINWINDOW_H
#define MAIN_CPP_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>


class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    QLabel * text;
    QPushButton * button;
};


#endif //MAIN_CPP_MAINWINDOW_H
