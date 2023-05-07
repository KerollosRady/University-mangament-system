#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <student.h>
namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr  , Student *stud = nullptr);
    ~Frame();

private:
    Ui::Frame *ui;
    Student *stud ;
public :
    void load_data() ;
private slots:
    void on_ChangePassBtn_clicked();
};

#endif // FRAME_H
