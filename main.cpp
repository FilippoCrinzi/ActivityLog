#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include "Activity.h"
#include "Time.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow finestra;
    finestra.show();
    //QPushButton button("Hello world!", nullptr);
    //button.resize(200, 100);
   // button.show();
    return QApplication::exec();
}
