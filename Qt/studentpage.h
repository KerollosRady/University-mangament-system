#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QDialog>

namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    ~StudentPage();

private:
    Ui::StudentPage *ui;
};

#endif // STUDENTPAGE_H
