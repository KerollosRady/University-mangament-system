#ifndef REGISTERTIME_H
#define REGISTERTIME_H

#include <QDialog>
#include <data.h>

namespace Ui {
class RegisterTime;
}

class RegisterTime : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterTime(QWidget *parent = nullptr , Data * data = nullptr);
    ~RegisterTime();

private slots:
    void on_save_clicked();

    void on_open_clicked();

    void on_close_clicked();

private:
    Ui::RegisterTime *ui;
    Data *data;
    bool openPage ;
};

#endif // REGISTERTIME_H
