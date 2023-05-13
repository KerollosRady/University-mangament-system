#ifndef COURSEVISUALIZE_H
#define COURSEVISUALIZE_H

#include <QWidget>

namespace Ui {
class CourseVisualize;
}

class CourseVisualize : public QWidget
{
    Q_OBJECT

public:
    explicit CourseVisualize(QWidget *parent = nullptr);
    ~CourseVisualize();

private:
    Ui::CourseVisualize *ui;
};

#endif // COURSEVISUALIZE_H
