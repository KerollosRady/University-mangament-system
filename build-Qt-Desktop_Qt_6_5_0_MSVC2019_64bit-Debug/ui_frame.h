/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QLabel *username;
    QLabel *Email;
    QPushButton *ChangePassBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *Email_2;
    QLabel *label_4;
    QLineEdit *newPass;
    QLabel *label_5;
    QLabel *id;
    QLabel *AcadimicYear;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *AllowedHours;
    QLabel *label_8;

    void setupUi(QFrame *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName("Frame");
        Frame->resize(721, 581);
        Frame->setStyleSheet(QString::fromUtf8("    font-weight: 600;\n"
"    color: #ffffff;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1c335f, stop:1 #13112d);\n"
""));
        username = new QLabel(Frame);
        username->setObjectName("username");
        username->setGeometry(QRect(160, 160, 271, 71));
        username->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        username->setAlignment(Qt::AlignCenter);
        Email = new QLabel(Frame);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(160, 250, 271, 71));
        Email->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        Email->setAlignment(Qt::AlignCenter);
        ChangePassBtn = new QPushButton(Frame);
        ChangePassBtn->setObjectName("ChangePassBtn");
        ChangePassBtn->setGeometry(QRect(480, 450, 171, 61));
        ChangePassBtn->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(Frame);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 160, 121, 71));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 250, 121, 71));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 340, 121, 71));
        label_3->setAlignment(Qt::AlignCenter);
        Email_2 = new QLabel(Frame);
        Email_2->setObjectName("Email_2");
        Email_2->setGeometry(QRect(160, 340, 271, 71));
        Email_2->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        Email_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 440, 121, 71));
        label_4->setAlignment(Qt::AlignCenter);
        newPass = new QLineEdit(Frame);
        newPass->setObjectName("newPass");
        newPass->setGeometry(QRect(160, 440, 271, 71));
        newPass->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        newPass->setEchoMode(QLineEdit::Password);
        newPass->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(460, 160, 91, 71));
        label_5->setAlignment(Qt::AlignCenter);
        id = new QLabel(Frame);
        id->setObjectName("id");
        id->setGeometry(QRect(570, 160, 121, 71));
        id->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        id->setAlignment(Qt::AlignCenter);
        AcadimicYear = new QLabel(Frame);
        AcadimicYear->setObjectName("AcadimicYear");
        AcadimicYear->setGeometry(QRect(570, 250, 121, 71));
        AcadimicYear->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        AcadimicYear->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(460, 250, 91, 71));
        label_6->setStyleSheet(QString::fromUtf8("font-size:13px;"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(460, 350, 91, 71));
        label_7->setStyleSheet(QString::fromUtf8("font-size:13px;"));
        label_7->setAlignment(Qt::AlignCenter);
        AllowedHours = new QLabel(Frame);
        AllowedHours->setObjectName("AllowedHours");
        AllowedHours->setGeometry(QRect(570, 350, 121, 71));
        AllowedHours->setStyleSheet(QString::fromUtf8("    border-radius: 10px;\n"
"\n"
"text-align:center;"));
        AllowedHours->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 30, 411, 111));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"color:rgb(255, 255, 255);\n"
"font: 36pt \"Castellar\";\n"
"    font-weight: 900;\n"
"    background-color: transparent;\n"
"\n"
""));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QFrame *Frame)
    {
        Frame->setWindowTitle(QCoreApplication::translate("Frame", "Frame", nullptr));
        username->setText(QString());
        Email->setText(QString());
        ChangePassBtn->setText(QCoreApplication::translate("Frame", "Change Password", nullptr));
        label->setText(QCoreApplication::translate("Frame", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("Frame", "Email", nullptr));
        label_3->setText(QCoreApplication::translate("Frame", "Password", nullptr));
        Email_2->setText(QString());
        label_4->setText(QCoreApplication::translate("Frame", "New Password", nullptr));
        newPass->setPlaceholderText(QCoreApplication::translate("Frame", "Write a new password", nullptr));
        label_5->setText(QCoreApplication::translate("Frame", "ID", nullptr));
        id->setText(QString());
        AcadimicYear->setText(QString());
        label_6->setText(QCoreApplication::translate("Frame", "Acadimic Year", nullptr));
        label_7->setText(QCoreApplication::translate("Frame", "Allowed Hours", nullptr));
        AllowedHours->setText(QString());
        label_8->setText(QCoreApplication::translate("Frame", "MY PROFILE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
