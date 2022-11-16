#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"reservation.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <QIntValidator>
#include <QVector>
#include <qjsondocument.h>
#include <QSortFilterProxyModel>

#include <QFile>
#include <QInputDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QNetworkSession>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_b_ajouter_clicked();

    void on_supprimer_clicked();

    void on_b_modifier_clicked();

    void on_pushButton_pdf_clicked();

    void on_tri_nom_clicked();

    void on_pushButton_2_clicked();

    void on_statistique_clicked();

    void on_pushButton_3_clicked();


    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_add_clicked();

    void readfile();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    reservation r;

QNetworkAccessManager *manager;

    QByteArray token = "";
    QByteArray user = "";
    QByteArray name = "";

    QJsonObject json;
    QJsonArray selected_day_json;
    QString select_date;

    QByteArray post(QString url, QByteArray data, const char *type);
    QByteArray get(QString url);
    QJsonObject format(QByteArray data);
    void updatetoken(QNetworkReply *reply);
};

#endif // MAINWINDOW_H
