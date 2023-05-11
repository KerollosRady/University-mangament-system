#ifndef NEWCOURSE_H
#define NEWCOURSE_H
#include <QDialog>
#include <string>
#include "course.h"
#include <data.h>
#include <Qtimer>
namespace Ui {
class newCourse;
}

class newCourse : public QDialog
{
    Q_OBJECT

public:
    explicit newCourse(QWidget *parent = nullptr, Data *data = nullptr);
    bool isInt(std::string);
    void invalidInputData(int);
    void clear();
    ~newCourse();

private slots:
    void on_Add_clicked();

    void on_clear_clicked();

private:
    Ui::newCourse *ui;
    Data* data;
};

#endif // NEWCOURSE_H
