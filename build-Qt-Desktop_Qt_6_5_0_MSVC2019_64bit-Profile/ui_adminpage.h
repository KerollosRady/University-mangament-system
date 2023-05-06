/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminPage
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QListView *listView;
    QPushButton *ViewCourse;
    QPushButton *EditCourse;
    QPushButton *ViewStudent;
    QPushButton *NewStudent;
    QPushButton *HomeButton;
    QLabel *label;
    QPushButton *profile;
    QPushButton *NewCourse;
    QLabel *name;
    QPushButton *logout;

    void setupUi(QDialog *AdminPage)
    {
        if (AdminPage->objectName().isEmpty())
            AdminPage->setObjectName("AdminPage");
        AdminPage->resize(1287, 662);
        AdminPage->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
"border-radius:10px;"));
        scrollArea = new QScrollArea(AdminPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(330, 110, 951, 551));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color:#eee;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 951, 551));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(930, 10, 16, 531));
        verticalScrollBar->setOrientation(Qt::Vertical);
        scrollArea->setWidget(scrollAreaWidgetContents);
        listView = new QListView(AdminPage);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(5, -20, 321, 691));
        ViewCourse = new QPushButton(AdminPage);
        ViewCourse->setObjectName("ViewCourse");
        ViewCourse->setGeometry(QRect(100, 460, 161, 71));
        ViewCourse->setCursor(QCursor(Qt::PointingHandCursor));
        ViewCourse->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:18px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        EditCourse = new QPushButton(AdminPage);
        EditCourse->setObjectName("EditCourse");
        EditCourse->setGeometry(QRect(100, 550, 161, 71));
        EditCourse->setCursor(QCursor(Qt::PointingHandCursor));
        EditCourse->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:18px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        ViewStudent = new QPushButton(AdminPage);
        ViewStudent->setObjectName("ViewStudent");
        ViewStudent->setGeometry(QRect(100, 280, 161, 71));
        ViewStudent->setCursor(QCursor(Qt::PointingHandCursor));
        ViewStudent->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:18px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        NewStudent = new QPushButton(AdminPage);
        NewStudent->setObjectName("NewStudent");
        NewStudent->setGeometry(QRect(100, 190, 161, 71));
        NewStudent->setCursor(QCursor(Qt::PointingHandCursor));
        NewStudent->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:20px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        HomeButton = new QPushButton(AdminPage);
        HomeButton->setObjectName("HomeButton");
        HomeButton->setGeometry(QRect(110, 100, 141, 71));
        HomeButton->setCursor(QCursor(Qt::PointingHandCursor));
        HomeButton->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:20px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        label = new QLabel(AdminPage);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 261, 91));
        label->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font: 25pt \"Castellar\";\n"
"    font-weight: 900;\n"
"    background-color: transparent;\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);
        profile = new QPushButton(AdminPage);
        profile->setObjectName("profile");
        profile->setGeometry(QRect(960, 20, 151, 61));
        profile->setCursor(QCursor(Qt::PointingHandCursor));
        profile->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:20px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        NewCourse = new QPushButton(AdminPage);
        NewCourse->setObjectName("NewCourse");
        NewCourse->setGeometry(QRect(100, 370, 161, 71));
        NewCourse->setCursor(QCursor(Qt::PointingHandCursor));
        NewCourse->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:20px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        name = new QLabel(AdminPage);
        name->setObjectName("name");
        name->setGeometry(QRect(440, 40, 191, 31));
        name->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 16pt \"Arial\";\n"
"    background-color: transparent;\n"
""));
        logout = new QPushButton(AdminPage);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(1130, 20, 141, 61));
        logout->setCursor(QCursor(Qt::PointingHandCursor));
        logout->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"	font-size:20px;\n"
"    border-radius: 30px;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        listView->raise();
        scrollArea->raise();
        ViewCourse->raise();
        EditCourse->raise();
        ViewStudent->raise();
        NewStudent->raise();
        HomeButton->raise();
        label->raise();
        profile->raise();
        NewCourse->raise();
        name->raise();
        logout->raise();

        retranslateUi(AdminPage);

        QMetaObject::connectSlotsByName(AdminPage);
    } // setupUi

    void retranslateUi(QDialog *AdminPage)
    {
        AdminPage->setWindowTitle(QCoreApplication::translate("AdminPage", "Dialog", nullptr));
        ViewCourse->setText(QCoreApplication::translate("AdminPage", "View Courses", nullptr));
        EditCourse->setText(QCoreApplication::translate("AdminPage", "Edit Course", nullptr));
        ViewStudent->setText(QCoreApplication::translate("AdminPage", "View Students", nullptr));
        NewStudent->setText(QCoreApplication::translate("AdminPage", "New Student", nullptr));
        HomeButton->setText(QCoreApplication::translate("AdminPage", "Home", nullptr));
        label->setText(QCoreApplication::translate("AdminPage", "Dash Board", nullptr));
        profile->setText(QCoreApplication::translate("AdminPage", "View Profile", nullptr));
        NewCourse->setText(QCoreApplication::translate("AdminPage", "New Course", nullptr));
        name->setText(QCoreApplication::translate("AdminPage", "Admin Name", nullptr));
        logout->setText(QCoreApplication::translate("AdminPage", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPage: public Ui_AdminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
