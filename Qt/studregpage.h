#ifndef STUDREGPAGE_H
#define STUDREGPAGE_H

#include <QDialog>
#include <data.h>

namespace Ui {
class StudRegPage;
}

class StudRegPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudRegPage(QWidget *parent = nullptr, Data * data = nullptr);
    ~StudRegPage();

private:
    Ui::StudRegPage *ui;
    Data *data;
};

#endif // STUDREGPAGE_H
