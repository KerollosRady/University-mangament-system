#include <FileHandling.cpp>
#include "loginpage.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    vector<Student> s = {
        Student(2023, 111, "ahmed", 5),
        Student(2023, 222, "samir", 5),
        Student(2023, 333, "hassan", 5)
    };

    int arr[3] = {1,5232,3};
    UploadDataToFile("Students.txt", arr);
//    LoadDataFromFile("Students.txt", arr);
    cout << "------------------------Hey\n";
    for (auto& x : arr)
        cout << x << ' ';
    cout << "------------------------Hey\n";

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
    LoginPage w;
    return a.exec();
}
