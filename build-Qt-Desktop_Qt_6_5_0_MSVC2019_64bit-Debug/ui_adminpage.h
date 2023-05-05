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

QT_BEGIN_NAMESPACE

class Ui_AdminPage
{
public:
    QLabel *label;

    void setupUi(QDialog *AdminPage)
    {
        if (AdminPage->objectName().isEmpty())
            AdminPage->setObjectName("AdminPage");
        AdminPage->resize(1287, 662);
        label = new QLabel(AdminPage);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1301, 671));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("background : rgb(222, 169, 255)rgb(221, 223, 255)"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(AdminPage);

        QMetaObject::connectSlotsByName(AdminPage);
    } // setupUi

    void retranslateUi(QDialog *AdminPage)
    {
        AdminPage->setWindowTitle(QCoreApplication::translate("AdminPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AdminPage", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Admin Page </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPage: public Ui_AdminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
