#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include <newCourse.h>
#include "adminwelcome.h"
namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_logout_clicked();

    void on_NewCourse_clicked();
    void on_HomeButton_clicked();

private:
    Ui::AdminPage *ui;
    newCourse * ptrCourse ;
    adminwelcome * welcome;
};

#endif // ADMINPAGE_H
