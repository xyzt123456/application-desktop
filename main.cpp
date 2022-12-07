#include "ig_materiel.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QPlainTextEdit>
#include<QTextDocument>
#include<QtWidgets/QMainWindow>
#include<QFile>
#include<QFont>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Connection c;
    bool test=c.createconnect();
    Ig_Materiel w;
    w.setWindowTitle("SQUADDESK");
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();

}
