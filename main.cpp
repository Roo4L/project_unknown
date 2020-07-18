#include "mainwindow.h"
#include "mainWidg.h"
#include "mainApp.h"
#include <QSplashScreen>
#include <QTime>
#include <QLabel>
#include <QApplication>

void loadModules(QSplashScreen*);

int main(int argc, char *argv[])
{
    App a(argc, argv,
          "GoldFishProduction",
          "WorkDog v.0.1");
    MainWindow w;
    QSplashScreen splash(QPixmap("/home/leggalaxycode/pureProject_Unknown/img/icon.jpg"));
    MainWidget mw;
    mw.setWindowTitle("WorkDog v. 0.1");

    //splash.resize(400, 400);
    splash.show();
    QLabel lbl("Application is ready");
    loadModules(&splash);
    splash.finish(&lbl);
    mw.show();
    return a.exec();
}

void loadModules(QSplashScreen *psplash) {
    QTime time;
    time.start();
    for (unsigned i = 0; i < 100;) {
        if (time.elapsed() > 40) {
            time.start();
            ++i;
        }
    psplash->showMessage("Loading modules: " + QString::number(i) + "%",
                         Qt::AlignHCenter | Qt::AlignBottom, Qt::black);
    qApp->processEvents();
    }
};
