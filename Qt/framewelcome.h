#ifndef FRAMEWELCOME_H
#define FRAMEWELCOME_H

#include <QFrame>

namespace Ui {
class FrameWelcome;
}

class FrameWelcome : public QFrame
{
    Q_OBJECT

public:
    explicit FrameWelcome(QWidget *parent = nullptr);
    ~FrameWelcome();

private:
    Ui::FrameWelcome *ui;
};

#endif // FRAMEWELCOME_H
