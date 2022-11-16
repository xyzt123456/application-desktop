#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"reservation.h"

#include "calendrier.h"

#include<QIntValidator>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDataStream>

#include <QtWidgets>
#include <QVector>
#include <QSqlQuery>

#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_cin->setValidator( new QIntValidator(0,99999999,this));
   ui->tab_reservation->setModel(r.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readfile(){
    QString filename="C:/Users/khouloud/Desktop/gestion reservation/Histo/historique.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "fichier not existed ! "<<filename;
    }else{
        qDebug() << filename<<" ok ...";
    }
    QString line;
    ui->textHisto->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textHisto->setText(ui->textHisto->toPlainText()+line+"\n");
        }
    }
    file.close();
}


void MainWindow::on_b_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString num_salle=ui->le_num_salle->text();
    QString type=ui->le_type->text();
reservation R(cin,nom,prenom,num_salle,type);
bool test=R.ajouter();
if(test)
{


                  foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                               le->clear();}
                          QFile file("C:/Users/khouloud/Desktop/gestion reservation/Histo/historique.txt");
                          if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                              return;
                          QTextStream cout(&file);
                          QString d_info = QDateTime::currentDateTime().toString();
                          QString message2=" + "+d_info+" Une réservation a été ajouté sous le nom de mr/mme : "+nom+" " ""+prenom+"\n";
                          cout << message2;


                          ui->tab_reservation->setModel(r.afficher());
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("ajout effectuer.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

     }
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr("ajout n'est pas effectuer.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


 }



void MainWindow::on_supprimer_clicked()
{
    int cin= ui->le_cin_supp->text().toInt();
    QString cinn=ui->le_cin_supp->text();


    bool test=r.supprimer(cin);
    if (test)
    {
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                     le->clear();}
                QFile file("C:/Users/khouloud/Desktop/gestion reservation/Histo/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);//variable de pointeur aal fichier
                QString d_info = QDateTime::currentDateTime().toString();// trajaalek el date de systeme
                QString message2=" - "+d_info+" Une réservation a été supprimé sous la CIN : "+cinn+"\n";
                cout << message2;


        ui->tab_reservation->setModel(r.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
          {  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("suppression n'est pas effectué.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}
 }

void MainWindow::on_b_modifier_clicked()
{
    int cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString num_salle=ui->le_num_salle_2->text();
    QString type=ui->le_type_2->text();
     reservation R(cin,nom,prenom,num_salle,type);
    bool test=R.modifier();
    if (test)
    {

        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                     le->clear();}
                QFile file("C:/Users/khouloud/Desktop/gestion reservation/Histo/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);
                QString d_info = QDateTime::currentDateTime().toString();
                QString message2=" ~ "+d_info+" Une réservation a été modifié sous le nom de mr/mme : "+nom+" " ""+prenom+"\n";
                cout << message2;

        ui->tab_reservation->setModel(r.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("modification effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
           { QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("modification n'est pas effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_pdf_clicked()
{

        //pdf : vous trouver le fichier dans le dossier build

            QString strStream;
                        QTextStream out(&strStream);
                        const int rowCount = ui->tab_reservation->model()->rowCount();
                        const int columnCount =ui->tab_reservation->model()->columnCount();


                        out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("eleve")
                                <<  "</head>\n"
                                "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                    "<h1>Liste des Evenements</h1>"

                                    "<table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                            out << "<thead><tr bgcolor=#f0f0f0>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tab_reservation->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tab_reservation->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";
                            // data table
                               for (int row = 0; row < rowCount; row++) {
                                   out << "<tr>";
                                   for (int column = 0; column < columnCount; column++) {
                                       if (!ui->tab_reservation->isColumnHidden(column)) {
                                           QString data = ui->tab_reservation->model()->data(ui->tab_reservation->model()->index(row, column)).toString().simplified();
                                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                       }
                                   }
                                   out << "</tr>\n";
                               }
                               out <<  "</table>\n"
                                   "</body>\n"
                                   "</html>\n";



                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);


                //QTextDocument document;
                //document.setHtml(html);
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("mypdffile.pdf");
                document->print(&printer);

}

void MainWindow::on_tri_nom_clicked()
{
    ui->tab_reservation->setModel(r.trierreservation());
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tab_reservation->setModel(r.recherche_reservation(ui->recherche->text()));
}

void MainWindow::on_statistique_clicked()
{
    reservation r;
                QBarSet *set0 = new QBarSet("statistique : courbe");

                *set0 << r.statistiquesreservation("H30") <<r.statistiquesreservation("H31") <<r.statistiquesreservation("H32");


                QColor color(0x6568F3);
                set0->setColor(color);

                QBarSeries *series = new QBarSeries();
                series->append(set0);




                QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setTitle("");
                chart->setAnimationOptions(QChart::SeriesAnimations);
                chart->setBackgroundVisible(false);

                QColor bgColor(0xF4DCD3);
                               chart->setBackgroundBrush(QBrush(QColor(bgColor)));

                               chart->setBackgroundVisible(true);

                QStringList categories;
                categories << "H30" << "H31" << "H32";
                QBarCategoryAxis *axis = new QBarCategoryAxis();
                axis->append(categories);
                chart->createDefaultAxes();
                chart->setAxisX(axis, series);

                QChartView *chartView = new QChartView(chart);

                chartView->setMinimumWidth(500);
                chartView->setMinimumHeight(300);
                chartView->setParent(ui->st);
                chart->legend()->setAlignment(Qt::AlignBottom);
                chartView->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    {

        bool ok;

        QString text = QInputDialog::getText(

            this, tr("Evenement d'entré"), tr("Veuillez entrer le nom de l'événement"), QLineEdit::Normal, 0, &ok);

        if (!ok || text.isEmpty()) return;



        auto date = ui->calendarWidget->selectedDate();



        QString event_title = text;

        QString event_start = "";

        QString event_end = "";

        QString event_local = "";

        QString _method = "POST";

        date = date.addDays(-1);

        event_start = event_end = date.toString("yyyy-MM-ddT16%3A00%3A00Z");



        QByteArray byte;

        byte.append("calendar_event%5Btitle%5D=" + event_title.toUtf8());

        byte.append("&calendar_event%5Bstart_at%5D=" + event_start.toUtf8());

        byte.append("&calendar_event%5Bend_at%5D=" + event_end.toUtf8());

        byte.append("&calendar_event%5Blocation_name%5D=" + event_local.toUtf8());

     //   byte.append("&calendar_event%5Bcontext_code%5D=user_" + user);

        byte.append("&_method=POST");

       // byte.append("&authenticity_token=" + token);

        QString url = "http://canvas.tongji.edu.cn/api/v1/calendar_events";

        //auto re = post(url, byte, "application/x-www-form-urlencoded");



       /* auto document = QJsonDocument::fromJson(re);

        auto object = document.object();

        auto value = object.value("id");

        auto plid = value.toInt();*/



        QJsonObject temp;

        temp.insert("context_name", QString(name));

        temp.insert("context_type", "User");

        QString d = date.toString("yyyy-MM-dd");

        d = d + "T16:00:00Z";

        temp.insert("plannable_date", d);

        QJsonObject pl;

        pl.insert("title", text);

        temp.insert("plannable", QJsonValue(pl));

       // temp.insert("plannable_id", plid);

       /* QJsonValueRef ref = this->json.find(this->select_date).value();

        QJsonArray arr = ref.toArray();

        arr.append(temp);

        ref = arr;*/



        auto format =

            ui->calendarWidget->dateTextFormat(ui->calendarWidget->selectedDate());

        format.setBackground(QColor("#00FFFF"));

        ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),

                                              format);



      //  on_calendarWidget_clicked(ui->calendarWidget->selectedDate());

    }


}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    this->select_date = date.toString("yyyy-MM-dd");
    this->selected_day_json = this->json[date.toString("yyyy-MM-dd")].toArray();
    if (selected_day_json.size()) {
       // ui->comboBox->clear();
        for (int i = 0; i < selected_day_json.size(); i++) {
            auto context_name =
                selected_day_json[i].toObject()["context_name"].toString();
          //  ui->comboBox->addItem(context_name);
        }
    } else {

        ui->lineEdit_num_salle->setText("1");
        auto format = ui->calendarWidget->dateTextFormat(
            ui->calendarWidget->selectedDate());
        format.setBackground(QColor("#FFFFFF"));
        ui->calendarWidget->setDateTextFormat(
            ui->calendarWidget->selectedDate(), format);
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    {
        bool ok;
        QString text = QInputDialog::getText(
            this, tr("Evenement d'entré"), tr("Veuillez entrer le nom de l'événement"), QLineEdit::Normal, 0, &ok);
        if (!ok || text.isEmpty()) return;

        auto date = ui->calendarWidget->selectedDate();

        QString event_title = text;
        QString event_start = "";
        QString event_end = "";
        QString event_local = "";
        QString _method = "POST";
        date = date.addDays(-1);
        event_start = event_end = date.toString("yyyy-MM-ddT16%3A00%3A00Z");

        QByteArray byte;
        byte.append("calendar_event%5Btitle%5D=" + event_title.toUtf8());
        byte.append("&calendar_event%5Bstart_at%5D=" + event_start.toUtf8());
        byte.append("&calendar_event%5Bend_at%5D=" + event_end.toUtf8());
        byte.append("&calendar_event%5Blocation_name%5D=" + event_local.toUtf8());
     //   byte.append("&calendar_event%5Bcontext_code%5D=user_" + user);
        byte.append("&_method=POST");
       // byte.append("&authenticity_token=" + token);
        QString url = "http://canvas.tongji.edu.cn/api/v1/calendar_events";
        //auto re = post(url, byte, "application/x-www-form-urlencoded");

       /* auto document = QJsonDocument::fromJson(re);
        auto object = document.object();
        auto value = object.value("id");
        auto plid = value.toInt();*/

        QJsonObject temp;
        temp.insert("context_name", QString(name));
        temp.insert("context_type", "User");
        QString d = date.toString("yyyy-MM-dd");
        d = d + "T16:00:00Z";
        temp.insert("plannable_date", d);
        QJsonObject pl;
        pl.insert("title", text);
        temp.insert("plannable", QJsonValue(pl));
       // temp.insert("plannable_id", plid);
       /* QJsonValueRef ref = this->json.find(this->select_date).value();
        QJsonArray arr = ref.toArray();
        arr.append(temp);
        ref = arr;*/

        auto format =
            ui->calendarWidget->dateTextFormat(ui->calendarWidget->selectedDate());
        format.setBackground(QColor("#00FFFF"));
        ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),
                                              format);

      //  on_calendarWidget_clicked(ui->calendarWidget->selectedDate());
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    readfile();
}
