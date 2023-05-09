#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <course.h>
#include <student.h>
namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr , vector<Course> * courses= nullptr , Student * stud  = nullptr  );
    ~RegisterForm();

private slots:
    void on_courseList_currentIndexChanged(int index);

    void on_RegisterButton_clicked();
private:
    Ui::RegisterForm *ui;
    vector<Course> * courses ;
    Student * stud  ;
public :
    void invalidMessages(int i) ;

};

#endif // REGISTERFORM_H
