#ifndef NEWCOURSE_H
#define NEWCOURSE_H
#include <QDialog>
#include <string>
#include "invaliddata.h"
#include "course.h"
namespace Ui {
class newCourse;
}

class newCourse : public QDialog
{
    Q_OBJECT

public:
    explicit newCourse(QWidget *parent = nullptr);
    bool isInt(std::string);
    ~newCourse();

private slots:
    void on_Add_clicked();

private:
    Ui::newCourse *ui;
};

#endif // NEWCOURSE_H
