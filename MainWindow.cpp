//
// Created by Filippo Crinzi on 13/02/23.
//

#include "MainWindow.h"
#include "Log.h"
#include <QDate>
#include <QLabel>
#include <QString>
#include <QTabWidget>
#include <QTime>

//


MainWindow::MainWindow(Log log, Date day) {

    this->setFixedSize(QSize(600, 400));

    this->setFixedSize(QSize(600, 400));

    date = QDate(day.getYear(), day.getMonth(), day.getDay());
    this->setWindowTitle(date.toString());
    viewDay = new QLabel(date.toString(), this);
    viewDay->setGeometry(QRect(QPoint(150, 15), QSize(300, 100)));
    viewDay->setStyleSheet("QLabel { background-color : grey; color : white; font-size: 21px; }");
    viewDay->setAlignment(Qt::AlignCenter);

    std::list<Activity> ScrollList = log.find(day);

    if (ScrollList.empty()) {

        activityTab = new QTableWidget(1, 3, this);
        activityTab->setGeometry(QRect(QPoint(100, 150), QSize(400, 200)));

        QTableWidgetItem *description = new QTableWidgetItem(tr("DESCRIZIONE"));
        QTableWidgetItem *start = new QTableWidgetItem(tr("INIZIO"));
        QTableWidgetItem *finish = new QTableWidgetItem(tr("FINE"));
        activityTab->setItem(0, 0, description);
        activityTab->setItem(0, 1, start);
        activityTab->setItem(0, 2, finish);

        QTableWidgetItem *emptyMessage = new QTableWidgetItem(tr("Non ci sono attività registrate"));
        activityTab->setRowCount(2); // Aggiungi una seconda riga per il messaggio
        activityTab->setSpan(1, 0, 1, 3); // Unisci le celle in una sola riga
        emptyMessage->setTextAlignment(Qt::AlignCenter); // Centra il testo
        emptyMessage->setFlags(Qt::NoItemFlags); // Rende la cella non modificabile
        activityTab->setItem(1, 0, emptyMessage);
    } else {

        activityTab = new QTableWidget(ScrollList.size() + 1, 3, this);
        activityTab->setGeometry(QRect(QPoint(100, 150), QSize(400, 200)));
        QTableWidgetItem *description = new QTableWidgetItem(tr("%1").arg("DESCRIZIONE"));
        QTableWidgetItem *start = new QTableWidgetItem(tr("%1").arg("INIZIO"));
        QTableWidgetItem *finish = new QTableWidgetItem(tr("%1").arg("FINE"));
        activityTab->setItem(0, 0, description);
        activityTab->setItem(0, 1, start);
        activityTab->setItem(0, 2, finish);

        int c = 0;
        int r = 0;
        QTime Qstart;
        QTime Qfinish;

        for (auto itr = ScrollList.begin(); itr != ScrollList.end(); itr++) {
            c = 0;
            r++;
            Qstart = QTime(itr->getStart().getHour(), itr->getStart().getMinutes(), 00);
            Qfinish = QTime(itr->getFinish().getHour(), itr->getFinish().getMinutes(), 00);
            description = new QTableWidgetItem(tr("%1").arg(itr->getDescription()));
            start = new QTableWidgetItem(tr("%1").arg(Qstart.toString()));
            finish = new QTableWidgetItem(tr("%1").arg(Qfinish.toString()));

            activityTab->setItem(r, c, description);
            c++;
            activityTab->setItem(r, c, start);

            c++;
            activityTab->setItem(r, c, finish);

        }
    }


}


