/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_StudentPage
{
public:
    QLabel *label;

    void setupUi(QDialog *StudentPage)
    {
        if (StudentPage->objectName().isEmpty())
            StudentPage->setObjectName("StudentPage");
        StudentPage->resize(400, 300);
        label = new QLabel(StudentPage);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 401, 301));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("background : rgb(222, 169, 255)rgb(221, 223, 255)"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(StudentPage);

        QMetaObject::connectSlotsByName(StudentPage);
    } // setupUi

    void retranslateUi(QDialog *StudentPage)
    {
        StudentPage->setWindowTitle(QCoreApplication::translate("StudentPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StudentPage", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Student Page </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentPage: public Ui_StudentPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H
