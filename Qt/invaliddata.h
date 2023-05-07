#ifndef INVALIDDATA_H
#define INVALIDDATA_H

#include <QDialog>

namespace Ui {
class invalidData;
}

class invalidData : public QDialog
{
    Q_OBJECT

public:
    explicit invalidData(QWidget *parent = nullptr);
    ~invalidData();

private:
    Ui::invalidData *ui;
};

#endif // INVALIDDATA_H
