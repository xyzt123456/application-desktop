#ifndef LOGIN_H
#define LOGIN_H
#include "employes.h"
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTimer>
#include "integration.h"


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_login_2_clicked();

private:
    Ui::login *ui;

    integration *ma;
};

#endif // LOGIN_H











