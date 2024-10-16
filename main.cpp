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
        Log registro;
        Date d(29, 2, 2024);
        Date n(12, 7, 1999);
        Date c(20, 7, 2002);
        registro.addActivity(Activity("partita", Time(21, 00), Time(22, 00), n));
        registro.addActivity(Activity("scuola", Time(9, 15), Time(13, 15), n));
        registro.addActivity(Activity("studio", Time(14, 00), Time(17, 30), n));
        registro.addActivity(Activity("merenda", Time(18, 00), Time(18, 15), n));
        registro.addActivity(Activity("studio", Time(14, 00), Time(17, 30), Date(29, 2, 2024)));
        registro.addActivity(Activity("pranzo", Time(12, 15), Time(14, 00), d));
        registro.addActivity(Activity("pranzo", Time(13, 15), Time(14, 00), n));
        registro.addActivity(Activity("provaC", Time(12, 15), Time(14, 00), c));
        //registro.updateActivity(Activity("pranzo", Time(13, 15), Time(14, 00), n), Time(12,15), Log::FieldToUpdate::Start);
        //registro.removeActivity(Activity("partita", Time(21, 00), Time(22, 00), n));
        std::printf("\nnumero di attività: %d", registro.countActivities());
        MainWindow finestra(registro, n);
        finestra.show();
        return QApplication::exec();
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}
