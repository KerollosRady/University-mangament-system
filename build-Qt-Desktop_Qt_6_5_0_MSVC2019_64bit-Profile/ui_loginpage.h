/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QToolButton *toolButton_20;
    QLineEdit *username_11;
    QLabel *label_21;
    QLineEdit *password_11;
    QLabel *label_22;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(500, 500);
        LoginPage->setMaximumSize(QSize(500, 500));
        LoginPage->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
"color:white;"));
        centralwidget = new QWidget(LoginPage);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(40, 100, 400, 261));
        groupBox_2->setMaximumSize(QSize(500, 500));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        toolButton_20 = new QToolButton(groupBox_2);
        toolButton_20->setObjectName("toolButton_20");
        toolButton_20->setGeometry(QRect(250, 190, 93, 28));
        toolButton_20->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_20->setMouseTracking(false);
        toolButton_20->setStyleSheet(QString::fromUtf8("    background-color: #1c335f;\n"
"    border-radius: 10px;\n"
"    color: white;\n"
""));
        username_11 = new QLineEdit(groupBox_2);
        username_11->setObjectName("username_11");
        username_11->setGeometry(QRect(160, 80, 181, 41));
        username_11->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"background:white;\n"
"color:black;\n"
"text-align:center;"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(70, 80, 81, 41));
        label_21->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;\n"
"color:white;"));
        password_11 = new QLineEdit(groupBox_2);
        password_11->setObjectName("password_11");
        password_11->setGeometry(QRect(160, 130, 181, 41));
        password_11->setCursor(QCursor(Qt::PointingHandCursor));
        password_11->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"background:white;\n"
"color:black;\n"
"text-align:center;"));
        password_11->setEchoMode(QLineEdit::Password);
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(70, 130, 81, 41));
        label_22->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"font-weight: bold;\n"
"color:white;"));
        LoginPage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginPage);
        statusbar->setObjectName("statusbar");
        LoginPage->setStatusBar(statusbar);

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "LoginPage", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("LoginPage", " Login form", nullptr));
        toolButton_20->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        label_21->setText(QCoreApplication::translate("LoginPage", "    Email", nullptr));
        password_11->setText(QString());
        label_22->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
