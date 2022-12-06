#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "client.h"
#include "arduino.h"

#include<QMessageBox>
#include <QSqlQueryModel>
#include<QIntValidator>
#include <QString>
#include <QSqlQuery>

#include<QPainter>
#include<QTextDocument>
#include<QTextStream>
#include<QPdfWriter>
#include <QDataStream>
#include<QDesktopServices>
#include<QFontDatabase>
#include<QPlainTextEdit>

/*
#include<QCharts>
#include<QtCharts/QPieSeries>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSlice>
#include<QtCharts/QChart>
#include<QtCharts/QChartView>
#include<QtCharts/QPieSlice>

using namespace QtCharts;

*/

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_b_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    int tel=ui->le_tel->text().toInt();
    int nbr=ui->le_nbr->text().toInt();
    int code=ui->le_code->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_naisc=ui->la_date->text();
    QString type=ui->type->text();
    QString adresse=ui->la_adresse->text();
    QString date_de_res=ui->date_res->text();


    if (ui->rb1->isChecked())
    {type="etudiant";}

    if (ui->rb2->isChecked())
    {type="fonctionnaire";}


Client c(cin,nom,prenom,date_naisc,tel,type,nbr,adresse,date_de_res,code);

    bool test=c.ajouter();

    if (test)

    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_client->setModel(c.afficher());

}
    else
    {QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_b_modifier_clicked()
{
    int cin=ui->le_cin_3->text().toInt();
    int tel=ui->le_tel_2->text().toInt();
    int nbr=ui->le_nbr2->text().toInt();
    int code=ui->le_code2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->la_adresse_2->text();
    QString date_naisc=ui->la_date2->text();
    QString date_de_res=ui->date_res2->text();
    QString type=ui->type->text();

    if (ui->rb1->isChecked())
    {type="etudiant";}

    if (ui->rb2->isChecked())
    {type="fonctionnaire";}

    Client c(cin,nom,prenom,date_naisc,tel,type,nbr,adresse,date_de_res,code);

    bool test=c.modifier();
            if (test)

            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("modification  effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tab_client->setModel(c.afficher());

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("modification non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            if (ui->rb1_2->isChecked())
            {type="etudiant";}

            if (ui->rb2_2->isChecked())
            {type="fonctionnaire";}
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator (new QIntValidator(100, 99999999, this));
    ui->le_tel->setValidator (new QIntValidator(100, 99999999, this));

    ui->tab_client->setModel(c.afficher());




    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}

void MainWindow::on_b_supprimer_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    bool test=c.supprimer(cin);
            if (test)

            {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("suppression effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("suppression non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_rechercher_clicked()
{
    QString recherche=ui->la_recherche->text();
    ui->tab_client->setModel(c.recherche_client(recherche));
}

void MainWindow::on_tri_clicked()
{
    ui->tab_client->setModel(c.tri_nom());
}




void MainWindow::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Elaa/OneDrive/Bureau/Gestion_client/Gestion_client/File.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::red);
        //QFontDatabase::addApplicationFont("../../Sangrita.tt f");
        painter.setFont(QFont("Arial", 30));
        painter.drawText(2500,1600,"Liste Des Clients");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Times", 50));
        painter.drawRect(2000,900,5500,1000);
        painter.drawPixmap(QRect(70,70,1500,1500),QPixmap("C:/Users/Elaa/OneDrive/Bureau/Gestion_client/logo.jpg"));
        painter.drawRect(10,3000,9000,550);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(200,3300,"Cin");
        painter.drawText(933,3300,"Nom");
        painter.drawText(2000,3300,"Prénom");
        painter.drawText(3240,3300,"Date de naissance");
        painter.drawText(5200,3300,"Téléphone");
        painter.drawText(6565,3300,"Type");
        painter.drawText(7565,3300,"Adresse");



        QSqlQuery query;
        query.prepare("select * from client");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(933,i,query.value(1).toString());
            painter.drawText(2000,i,query.value(2).toString());
            painter.drawText(3240,i,query.value(3).toString());
            painter.drawText(5300,i,query.value(4).toString());

            if(query.value(5).toString()=="type")
                painter.drawText(6232,i,"etudiant");
            else
                painter.drawText(6232,i,"fonctionnaire");





            painter.drawText(7565,i,query.value(7).toString());
             i = i +500;

        }
        int reponse = QMessageBox::question(this, "PDF Enregistrer", "Voulez-vous Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Elaa/OneDrive/Bureau/Gestion_client/Gestion_client/File.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
    }





void MainWindow::on_fd_clicked()
{
    ui->tab_client->setModel(c.client_fidele());

    if (c.getNbr()>=5)
        {
            QMessageBox::information(nullptr, QObject::tr("Client fidèle"),
                        QObject::tr("Voilà les client qui ont une visite gratuite et une place dans le parking.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_client->setModel(c.client_fidele());

    }
        else
        {
        QMessageBox::critical(nullptr, QObject::tr("Client fidèle"),
                    QObject::tr("Voilà les client qui ont une visite gratuite et une place dans le parking.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
        QMessageBox msgBox;
        QString ch=QString(data);

        QSqlQuery query;
        query.prepare("select * from client where code='"+ch+"'");

        QSqlQueryModel * model2= new QSqlQueryModel();
            model2->setQuery("select * from client where code='"+ch+"'");
            int z=0;
                    z=model2->rowCount();

         if(query.exec() and z>0)
         {
             msgBox.setText("Accès au parking avec succès.");
             A.write_to_arduino("1");
         }
         else if (z==0)
         {
             msgBox.setText("Accès au parking impossible.");
             A.write_to_arduino("0");
         }



           /* else if (data=="0")
            {
                msgBox.setText("Accès au parking impossible.");
                A.write_to_arduino("0");
                z=0;
            }*/

    msgBox.exec();

}


/*
void MainWindow::on_stat_clicked()
{
    QBarSet *set0=new QBarSet("Fonctionnaire");
        QBarSet *set1=new QBarSet("Etudiant");

        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from client where type=fonctionnaire ");
            int etat0=model->rowCount();
            model->setQuery("select * from materiel where type=etudiant");
            int etat1=model->rowCount();

        *set0<<etat0;
        *set1<<etat1;

        QBarSeries *series= new QBarSeries();

        series->append(set0);
        series->append(set1);


        QChart *chart= new QChart();
        chart->addSeries(series);
        QFont font;
        font.setPixelSize(18);
        chart->setTitleFont(font);
        chart->setTitle("Les types des clients");
        chart->setAnimationOptions(QChart::AllAnimations);

        QStringList cat_etats;
        cat_etats<<"Fonctionnaire"<<"Etudiant";

        QBarCategoryAxis *axis= new QBarCategoryAxis();
        //axis->append(cat_etats);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QPalette pal=qApp->palette();
        pal.setColor(QPalette::Window,QRgb(0x601700));
        pal.setColor(QPalette::WindowText,QRgb(0x601700));
        qApp->setPalette(pal);

        QChartView *chartView= new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}
*/



void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("elaa.soua@esprit.tn","53621299","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

  if( !files.isEmpty() )
        smtp->sendMail("squad.desk2002@gmail.com", ui->rcpt->text(), ui->subject->text(), ui->msg->toPlainText());
    else
        smtp->sendMail("squad.desk2002@gmail.com", ui->rcpt->text(), ui->subject->text(), ui->msg->toPlainText());

   ui->rcpt->setText("");
   ui->subject->setText("");
   ui->msg->setPlainText("");

}
void MainWindow::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}
