#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>

//Graphique
QChartView* MainWindow::piechart()
{

    QPieSeries *series = new QPieSeries();
    series->append("reunion", 1);
    series->append("event", 2);
    series->append("revision", 3);
    series->append("travail", 4);

    // Add label to 1st slice

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setExploded();
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    // Add labels to rest of slices
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setExploded();
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::darkRed, 2));
    slice2->setBrush(Qt::red);

    QPieSlice *slice3 = series->slices().at(3);
    slice3->setExploded();
    slice3->setLabelVisible();
    slice3->setPen(QPen(Qt::darkBlue, 2));
    slice3->setBrush(Qt::blue);


    //ajouter une fonction pour  chaque slice
    series->slices().at(0)->setValue(G_PVS1());
    series->slices().at(1)->setValue(G_PVS2());
    series->slices().at(2)->setValue(G_PVS3());
    series->slices().at(3)->setValue(G_PVS4());

    series->slices().at(0)->setBrush(Qt::darkMagenta);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" type des salles ");


    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);
    return chartView1;
}

//fonction selon le type pour la selection
int MainWindow::G_PVS1()
{

    int c22=0;
    QSqlQuery qry22;
    qry22.exec("SELECT id FROM salle WHERE type='reunion'");
    while(qry22.next())
    {
        c22++;
    }
    return c22;
}

int MainWindow::G_PVS2()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT id FROM salle WHERE type='event' ");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}

int MainWindow::G_PVS3()
{
    int c20=0;
    QSqlQuery qry20;
    qry20.exec("SELECT id FROM salle WHERE type='revision' ");
    while(qry20.next())
    {
        c20++;
    }
    return c20;
}

int MainWindow::G_PVS4()
{
    int c19=0;
    QSqlQuery qry19;
    qry19.exec("SELECT id FROM salle WHERE type='travail' ");
    while(qry19.next())
    {
        c19++;
    }
    return c19;
}
