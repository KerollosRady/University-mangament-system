//#include <FileHandling.cpp>
#include "loginpage.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <time.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Qt_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    srand ( time(NULL) );
    LoginPage w;
    return a.exec();
}
