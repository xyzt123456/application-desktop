/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_mdp;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *le_cin;
    QLabel *label_2;
    QLineEdit *le_occupation;
    QLabel *label_6;
    QLineEdit *le_adresse;
    QLabel *label_5;
    QPushButton *pb_ajouter;
    QWidget *tab_2;
    QTableView *tab_employe;
    QWidget *tab_3;
    QLabel *label_7;
    QLineEdit *le_id_sup;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1060, 619);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 511, 411));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        le_id = new QLineEdit(tab);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(130, 10, 131, 31));
        le_nom = new QLineEdit(tab);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(130, 111, 131, 31));
        le_mdp = new QLineEdit(tab);
        le_mdp->setObjectName(QStringLiteral("le_mdp"));
        le_mdp->setGeometry(QRect(130, 260, 131, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 260, 101, 41));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 91, 41));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 81, 41));
        le_cin = new QLineEdit(tab);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(130, 61, 131, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 91, 41));
        le_occupation = new QLineEdit(tab);
        le_occupation->setObjectName(QStringLiteral("le_occupation"));
        le_occupation->setGeometry(QRect(130, 210, 131, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 91, 41));
        le_adresse = new QLineEdit(tab);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(130, 160, 131, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 210, 121, 41));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(320, 280, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_employe = new QTableView(tab_2);
        tab_employe->setObjectName(QStringLiteral("tab_employe"));
        tab_employe->setGeometry(QRect(10, 0, 401, 311));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 30, 56, 16));
        le_id_sup = new QLineEdit(tab_3);
        le_id_sup->setObjectName(QStringLiteral("le_id_sup"));
        le_id_sup->setGeometry(QRect(100, 70, 113, 22));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 140, 93, 28));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1060, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Noun", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Adress", Q_NULLPTR));
        le_adresse->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Occupation", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "afficher", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
