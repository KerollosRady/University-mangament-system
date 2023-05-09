//#include <FileHandling.cpp>
#include "loginpage.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <data.h>
unordered_map<string,set<int>> Data::filterByInstructor = {} ;
vector<set<int>> Data::filterByHours = {} ;
vector<set<int>> Data::filterByElectivity = {} ;
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
        }}
    LoginPage w;
    return a.exec();
}
