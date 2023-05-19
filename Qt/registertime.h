#ifndef REGISTERTIME_H
#define REGISTERTIME_H

#include <QDialog>
#include <data.h>
#include <QPushButton>

namespace Ui {
class RegisterTime;
}

class RegisterTime : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterTime(QWidget *parent = nullptr , Data * data = nullptr, QPushButton *semsterUpd = nullptr);
    ~RegisterTime();

private slots:
    void on_save_clicked();

    void on_open_clicked();

    void on_close_clicked();
    void semsterUpdButton();

private:
    Ui::RegisterTime *ui;
    Data *data;
    bool openPage ;
    QPushButton * semsterUpd;
};

#endif // REGISTERTIME_H
