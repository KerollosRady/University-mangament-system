#ifndef DEBUGING_H
#define DEBUGING_H

#include <QWidget>

namespace Ui {
class debuging;
}

class debuging : public QWidget
{
    Q_OBJECT

public:
    explicit debuging(QWidget *parent = nullptr);
    ~debuging();
    Ui::debuging *ui;
};

#endif // DEBUGING_H
