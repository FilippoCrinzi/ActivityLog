#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include "Activity.h"
#include "Time.h"
#include "MainWindow.h"
#include "Log.h"
#include "string"
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        QApplication a(argc, argv);
        Log Registro;
        Date d(29, 2, 2024);
        Date n(12, 7, 1999);
        Date c(20, 7, 2002);
        //Registro.AddActivity(n,Activity("studio",Time(14,00),Time(17,30)));
        Registro.AddActivity(d, Activity("partita", Time(21, 00), Time(22, 30)));
        Registro.AddActivity(d, Activity("scuola", Time(9, 15), Time(13, 15)));
        Registro.AddActivity(d, Activity("studio", Time(14, 00), Time(17, 30)));
        Registro.AddActivity(d, Activity("merenda", Time(18, 00), Time(18, 15)));
        Registro.AddActivity(n, Activity("studio", Time(14, 00), Time(17, 30)));
        Registro.AddActivity(n, Activity("pranzo", Time(12, 15), Time(14, 00)));
        Registro.AddActivity(d, Activity("pranzo con la Giulia <3", Time(12, 15), Time(14, 00)));
        MainWindow finestra(Registro, d);
        finestra.show();
        return QApplication::exec();
    }
    catch(std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}
