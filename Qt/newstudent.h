#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

#include <QDialog>

namespace Ui {
class newStudent;
}

class newStudent : public QDialog
{
    Q_OBJECT

public:
    explicit newStudent(QWidget *parent = nullptr);
    ~newStudent();

private:
    Ui::newStudent *ui;
};

#endif // NEWSTUDENT_H
