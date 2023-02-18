//
// Created by Filippo Crinzi on 13/02/23.
//

#include "MainWindow.h"
#include "Log.h"
#include <QDate>
#include <QLabel>
#include <QString>
#include <QTabWidget>

//


MainWindow::MainWindow(Log Register,Date day) {
    this->setFixedSize(QSize(600, 400));

    this->setWindowTitle("registro attività");
    this->setFixedSize(QSize(600, 400));
    text = QDate(day.getYear(),day.getMonth(),day.getDay() );
    std::list<Activity> ScrollList = Register.find(day);
    ViewDay = new QLabel(text.toString(),this);
    ViewDay->setGeometry(QRect(QPoint(150, 15), QSize(300, 100)));
    ViewDay->setStyleSheet("QLabel { background-color : grey; color : white; }");
    ViewDay->setAlignment(Qt::AlignCenter);
    ActivityTab = new QTableWidget(ScrollList.size()+1,3,this);
    ActivityTab->setGeometry(QRect(QPoint(100,150),QSize(400,200)));


}


