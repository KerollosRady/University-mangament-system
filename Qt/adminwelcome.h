#ifndef ADMINWELCOME_H
#define ADMINWELCOME_H

#include <QDialog>

namespace Ui {
class adminwelcome;
}

class adminwelcome : public QDialog
{
    Q_OBJECT

public:
    explicit adminwelcome(QWidget *parent = nullptr);
    ~adminwelcome();

private:
    Ui::adminwelcome *ui;
};

#endif // ADMINWELCOME_H
