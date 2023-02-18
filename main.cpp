#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include "Activity.h"
#include "Time.h"
#include "MainWindow.h"
#include "Log.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Log Registro;
    Date d(15,2,2023);
    Registro.AddActivity(d,Activity("partita",Time(21,00),Time(22,30)));
    Registro.AddActivity(d,Activity("scuola",Time(9,15),Time(13,15)));
    MainWindow finestra(Registro,d);

    finestra.show();
    //QPushButton button("Hello world!", nullptr);
    //button.resize(200, 100);
   // button.show();
    return QApplication::exec();
}
