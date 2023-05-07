#include <QDialog>
#include <QMainWindow>
namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr, QMainWindow * loginpage= nullptr);
    ~AdminPage();

private slots:
    void on_logout_clicked();

private:
    Ui::AdminPage *ui;
    QMainWindow * loginpage ;
};

