/********************************************************************************
** Form generated from reading UI file 'framewelcome.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEWELCOME_H
#define UI_FRAMEWELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrameWelcome
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *welcome_to_ums;

    void setupUi(QFrame *FrameWelcome)
    {
        if (FrameWelcome->objectName().isEmpty())
            FrameWelcome->setObjectName("FrameWelcome");
        FrameWelcome->resize(731, 600);
        scrollArea = new QScrollArea(FrameWelcome);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 731, 600));
        scrollArea->setMinimumSize(QSize(0, 600));
        scrollArea->setMaximumSize(QSize(16777215, 600));
        scrollArea->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 729, 598));
        welcome_to_ums = new QLabel(scrollAreaWidgetContents);
        welcome_to_ums->setObjectName("welcome_to_ums");
        welcome_to_ums->setGeometry(QRect(40, 110, 641, 351));
        welcome_to_ums->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font: 36pt \"Castellar\";\n"
"    font-weight: 900;\n"
"    background-color: transparent;\n"
"\n"
""));
        welcome_to_ums->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(FrameWelcome);

        QMetaObject::connectSlotsByName(FrameWelcome);
    } // setupUi

    void retranslateUi(QFrame *FrameWelcome)
    {
        FrameWelcome->setWindowTitle(QCoreApplication::translate("FrameWelcome", "Frame", nullptr));
        welcome_to_ums->setText(QCoreApplication::translate("FrameWelcome", "Welcome To Ums", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrameWelcome: public Ui_FrameWelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEWELCOME_H
