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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *stat;
    QWidget *tab;
    QGroupBox *Ajouter;
    QSpinBox *spinBox;
    QLineEdit *le_tel;
    QLabel *tel;
    QLabel *type;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QLabel *label_2;
    QLabel *cin;
    QLabel *nom;
    QLabel *prenom;
    QLabel *date_naisc;
    QLabel *adresse;
    QLineEdit *le_cin;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_adresse;
    QPushButton *b_ajouter;
    QDateEdit *la_date;
    QWidget *tab_3;
    QGroupBox *Ajouter_3;
    QLabel *cin_3;
    QLineEdit *le_cin_3;
    QLabel *nom_2;
    QLineEdit *le_nom_2;
    QLabel *prenom_2;
    QLineEdit *le_prenom_2;
    QLabel *date_naisc_2;
    QDateEdit *dateEdit;
    QLabel *tel_2;
    QLineEdit *le_tel_2;
    QLabel *adresse_2;
    QLineEdit *le_adresse_2;
    QPushButton *b_modifier;
    QLabel *type_3;
    QRadioButton *rb1_3;
    QRadioButton *rb2_3;
    QWidget *tab_2;
    QTableView *tab_client;
    QPushButton *tri;
    QLineEdit *la_recherche;
    QPushButton *rechercher;
    QPushButton *pdf;
    QPushButton *stat_2;
    QPushButton *fd;
    QWidget *tab_4;
    QGroupBox *groupBox_2;
    QPushButton *b_supprimer;
    QLineEdit *le_cin_2;
    QLabel *cin_2;
    QWidget *tab_6;
    QPushButton *envoyer;
    QLineEdit *mail;
    QTextEdit *textEdit;
    QTextEdit *textEdit_5;
    QLineEdit *sujet;
    QTextEdit *textEdit_6;
    QTextEdit *msg;
    QWidget *tab_5;
    QGroupBox *Ajouter_5;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuGESTION_DES_CLIENTS;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 634);
        MainWindow->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px white ;\n"
"     background-color: #601700;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #601700;\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"/*QWidget:item\n"
"{\n"
"	 border-top-color: #601700;\n"
"    border-color: #601700;\n"
"    color: #e0d0c1;\n"
"	background-color: #e0d0c1;\n"
"	\n"
"}*/\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #a07461);\n"
"    color: #601700;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 1 #a07461);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: white;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: "
                        "QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #601700;\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);*/\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color:white;\n"
"/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0 #a07461, stop: 1 #a074"
                        "61);*/\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #601700;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #e0d0c1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.1 #a07461, stop: 0.5 #a07461, stop: 0.9 #a07461, stop: 1 #e0d0c1);\n"
"    border-width: 1px;\n"
"    border-color: #601700;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0.2 #601700, stop: 0.5 #601700, stop: 0.8 #601700, stop: 1 #a07461);\n"
"/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0.1 #601700, stop: 0.5 #601700, stop: 0.9 #601700, stop: 1 #61700);*/\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0"
                        ", y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #ffffff;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 1 #c18c75);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid white;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     borde"
                        "r-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #a07461);*/\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #601700;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #601700, stop: 0.2 #601700, stop: 1 #601700);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 0.5 #e0d0c1"
                        ", stop: 1 #e0d0c1);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
""
                        "}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #601700, stop: 0.2 #601700, stop: 1 #601700);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #601700;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.5 #e0d0c1, stop: 1 #e0d0c1);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
" "
                        "     height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #e0d0c1;\n"
"border:#e0d0c1;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.2 #a07461, stop: 0.5 #a07461, stop: 0.8 #a07461, stop: 1 #e0d0c1);/*QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #c1b4a7, stop: 0.5 #8c6555, stop: 0.6 #601700, stop:1 #8c6555);*/\n"
"    color: #e0d0c1;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #601700;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
""
                        "}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px "
                        "solid #e0d0c1;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    b"
                        "ackground-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #e0d0c1;\n"
"    border: 1px solid #601700;\n"
"    border-bottom-style: none;\n"
"    background-color:   QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #601700, stop:.4 #841e00);;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #601700;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #601700;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    ba"
                        "ckground-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #a07461, stop:.4 #bc8872);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #a07461, stop:0.4 #bc8872, stop:0.2 #bc8872, stop:0.1 #a07461);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #601700;\n"
"    background-color: #a07461;\n"
"    border: 1px solid #601700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #e0d0c1,\n"
"        stop: 0.3 #601700\n"
"   "
                        " );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #601700;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stat = new QTabWidget(centralWidget);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(30, 70, 1081, 471));
        stat->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px white ;\n"
"     background-color: #601700;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #601700;\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"/*QWidget:item\n"
"{\n"
"	 border-top-color: #601700;\n"
"    border-color: #601700;\n"
"    color: #e0d0c1;\n"
"	background-color: #e0d0c1;\n"
"	\n"
"}*/\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #a07461);\n"
"    color: #601700;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 1 #a07461);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: white;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: "
                        "QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #601700;\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);*/\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color:white;\n"
"/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0 #a07461, stop: 1 #a074"
                        "61);*/\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #601700;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #e0d0c1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.1 #a07461, stop: 0.5 #a07461, stop: 0.9 #a07461, stop: 1 #e0d0c1);\n"
"    border-width: 1px;\n"
"    border-color: #601700;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0.2 #601700, stop: 0.5 #601700, stop: 0.8 #601700, stop: 1 #a07461);\n"
"/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 0.1 #601700, stop: 0.5 #601700, stop: 0.9 #601700, stop: 1 #61700);*/\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0"
                        ", y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #ffffff;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #a07461, stop: 1 #c18c75);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid white;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     borde"
                        "r-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #a07461);*/\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid #e0d0c1/*QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #601700;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #601700, stop: 0.2 #601700, stop: 1 #601700);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 0.5 #e0d0c1"
                        ", stop: 1 #e0d0c1);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
""
                        "}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #601700, stop: 0.2 #601700, stop: 1 #601700);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #601700;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.5 #e0d0c1, stop: 1 #e0d0c1);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #601700;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 1 #e0d0c1);\n"
" "
                        "     height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #e0d0c1;\n"
"border:#e0d0c1;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #e0d0c1;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e0d0c1, stop: 0.2 #a07461, stop: 0.5 #a07461, stop: 0.8 #a07461, stop: 1 #e0d0c1);/*QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #c1b4a7, stop: 0.5 #8c6555, stop: 0.6 #601700, stop:1 #8c6555);*/\n"
"    color: #e0d0c1;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #601700;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
""
                        "}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px "
                        "solid #e0d0c1;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    b"
                        "ackground-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #e0d0c1;\n"
"    border: 1px solid #601700;\n"
"    border-bottom-style: none;\n"
"    background-color:   QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #601700, stop:.4 #841e00);;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #601700;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #601700;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    ba"
                        "ckground-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #a07461, stop:.4 #bc8872);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #a07461, stop:0.4 #bc8872, stop:0.2 #bc8872, stop:0.1 #a07461);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #601700;\n"
"    background-color: #a07461;\n"
"    border: 1px solid #601700;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #e0d0c1,\n"
"        stop: 0.3 #601700\n"
"   "
                        " );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #601700;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Ajouter = new QGroupBox(tab);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(10, 0, 1031, 411));
        Ajouter->setCursor(QCursor(Qt::ArrowCursor));
        spinBox = new QSpinBox(Ajouter);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(170, 320, 42, 22));
        le_tel = new QLineEdit(Ajouter);
        le_tel->setObjectName(QStringLiteral("le_tel"));
        le_tel->setGeometry(QRect(160, 250, 141, 26));
        tel = new QLabel(Ajouter);
        tel->setObjectName(QStringLiteral("tel"));
        tel->setGeometry(QRect(40, 260, 81, 20));
        type = new QLabel(Ajouter);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(40, 290, 81, 20));
        rb1 = new QRadioButton(Ajouter);
        rb1->setObjectName(QStringLiteral("rb1"));
        rb1->setGeometry(QRect(150, 290, 97, 20));
        rb2 = new QRadioButton(Ajouter);
        rb2->setObjectName(QStringLiteral("rb2"));
        rb2->setGeometry(QRect(260, 290, 131, 20));
        label_2 = new QLabel(Ajouter);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 330, 121, 16));
        cin = new QLabel(tab);
        cin->setObjectName(QStringLiteral("cin"));
        cin->setGeometry(QRect(50, 60, 63, 20));
        nom = new QLabel(tab);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(50, 110, 71, 20));
        prenom = new QLabel(tab);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(50, 160, 63, 20));
        date_naisc = new QLabel(tab);
        date_naisc->setObjectName(QStringLiteral("date_naisc"));
        date_naisc->setGeometry(QRect(50, 210, 141, 20));
        adresse = new QLabel(tab);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(40, 360, 101, 20));
        le_cin = new QLineEdit(tab);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(170, 60, 141, 26));
        le_nom = new QLineEdit(tab);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(170, 110, 141, 26));
        le_prenom = new QLineEdit(tab);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(170, 160, 141, 26));
        le_adresse = new QLineEdit(tab);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(170, 360, 141, 26));
        b_ajouter = new QPushButton(tab);
        b_ajouter->setObjectName(QStringLiteral("b_ajouter"));
        b_ajouter->setGeometry(QRect(390, 360, 101, 29));
        b_ajouter->setStyleSheet(QStringLiteral("font: 11pt \"Segoe UI\";"));
        la_date = new QDateEdit(tab);
        la_date->setObjectName(QStringLiteral("la_date"));
        la_date->setGeometry(QRect(200, 210, 101, 26));
        stat->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        Ajouter_3 = new QGroupBox(tab_3);
        Ajouter_3->setObjectName(QStringLiteral("Ajouter_3"));
        Ajouter_3->setGeometry(QRect(20, 10, 1031, 411));
        cin_3 = new QLabel(Ajouter_3);
        cin_3->setObjectName(QStringLiteral("cin_3"));
        cin_3->setGeometry(QRect(40, 60, 63, 20));
        le_cin_3 = new QLineEdit(Ajouter_3);
        le_cin_3->setObjectName(QStringLiteral("le_cin_3"));
        le_cin_3->setGeometry(QRect(100, 60, 161, 26));
        nom_2 = new QLabel(Ajouter_3);
        nom_2->setObjectName(QStringLiteral("nom_2"));
        nom_2->setGeometry(QRect(40, 110, 71, 20));
        le_nom_2 = new QLineEdit(Ajouter_3);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(100, 110, 161, 26));
        prenom_2 = new QLabel(Ajouter_3);
        prenom_2->setObjectName(QStringLiteral("prenom_2"));
        prenom_2->setGeometry(QRect(40, 150, 63, 20));
        le_prenom_2 = new QLineEdit(Ajouter_3);
        le_prenom_2->setObjectName(QStringLiteral("le_prenom_2"));
        le_prenom_2->setGeometry(QRect(100, 150, 161, 26));
        date_naisc_2 = new QLabel(Ajouter_3);
        date_naisc_2->setObjectName(QStringLiteral("date_naisc_2"));
        date_naisc_2->setGeometry(QRect(40, 200, 141, 20));
        dateEdit = new QDateEdit(Ajouter_3);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(160, 200, 110, 26));
        tel_2 = new QLabel(Ajouter_3);
        tel_2->setObjectName(QStringLiteral("tel_2"));
        tel_2->setGeometry(QRect(40, 250, 81, 20));
        le_tel_2 = new QLineEdit(Ajouter_3);
        le_tel_2->setObjectName(QStringLiteral("le_tel_2"));
        le_tel_2->setGeometry(QRect(112, 250, 161, 26));
        adresse_2 = new QLabel(Ajouter_3);
        adresse_2->setObjectName(QStringLiteral("adresse_2"));
        adresse_2->setGeometry(QRect(40, 340, 63, 20));
        le_adresse_2 = new QLineEdit(Ajouter_3);
        le_adresse_2->setObjectName(QStringLiteral("le_adresse_2"));
        le_adresse_2->setGeometry(QRect(120, 340, 161, 26));
        b_modifier = new QPushButton(Ajouter_3);
        b_modifier->setObjectName(QStringLiteral("b_modifier"));
        b_modifier->setGeometry(QRect(400, 340, 93, 29));
        b_modifier->setStyleSheet(QStringLiteral("font: 11pt \"Segoe UI\";"));
        type_3 = new QLabel(Ajouter_3);
        type_3->setObjectName(QStringLiteral("type_3"));
        type_3->setGeometry(QRect(40, 300, 63, 20));
        rb1_3 = new QRadioButton(Ajouter_3);
        rb1_3->setObjectName(QStringLiteral("rb1_3"));
        rb1_3->setGeometry(QRect(110, 300, 97, 20));
        rb2_3 = new QRadioButton(Ajouter_3);
        rb2_3->setObjectName(QStringLiteral("rb2_3"));
        rb2_3->setGeometry(QRect(240, 300, 131, 20));
        stat->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_client = new QTableView(tab_2);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(10, 60, 951, 361));
        tri = new QPushButton(tab_2);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(970, 60, 93, 29));
        la_recherche = new QLineEdit(tab_2);
        la_recherche->setObjectName(QStringLiteral("la_recherche"));
        la_recherche->setGeometry(QRect(140, 10, 331, 26));
        rechercher = new QPushButton(tab_2);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(490, 10, 93, 29));
        rechercher->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px white ;\n"
"     background-color: #601700;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}"));
        pdf = new QPushButton(tab_2);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(970, 110, 93, 29));
        pdf->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px white ;\n"
"     background-color: #601700;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}"));
        stat_2 = new QPushButton(tab_2);
        stat_2->setObjectName(QStringLiteral("stat_2"));
        stat_2->setGeometry(QRect(970, 160, 93, 28));
        fd = new QPushButton(tab_2);
        fd->setObjectName(QStringLiteral("fd"));
        fd->setGeometry(QRect(970, 200, 93, 28));
        stat->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(260, 20, 371, 361));
        b_supprimer = new QPushButton(groupBox_2);
        b_supprimer->setObjectName(QStringLiteral("b_supprimer"));
        b_supprimer->setGeometry(QRect(110, 230, 131, 51));
        b_supprimer->setStyleSheet(QLatin1String("font: 22pt \"Segoe UI\";\n"
"font: 8pt \"Segoe UI\";"));
        le_cin_2 = new QLineEdit(groupBox_2);
        le_cin_2->setObjectName(QStringLiteral("le_cin_2"));
        le_cin_2->setGeometry(QRect(120, 120, 113, 26));
        cin_2 = new QLabel(groupBox_2);
        cin_2->setObjectName(QStringLiteral("cin_2"));
        cin_2->setGeometry(QRect(50, 120, 63, 20));
        stat->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        envoyer = new QPushButton(tab_6);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(720, 380, 93, 29));
        mail = new QLineEdit(tab_6);
        mail->setObjectName(QStringLiteral("mail"));
        mail->setGeometry(QRect(170, 30, 351, 26));
        textEdit = new QTextEdit(tab_6);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 104, 31));
        textEdit_5 = new QTextEdit(tab_6);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(20, 70, 151, 31));
        sujet = new QLineEdit(tab_6);
        sujet->setObjectName(QStringLiteral("sujet"));
        sujet->setGeometry(QRect(170, 70, 351, 26));
        textEdit_6 = new QTextEdit(tab_6);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(20, 110, 151, 31));
        msg = new QTextEdit(tab_6);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(40, 160, 641, 341));
        stat->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        Ajouter_5 = new QGroupBox(tab_5);
        Ajouter_5->setObjectName(QStringLiteral("Ajouter_5"));
        Ajouter_5->setGeometry(QRect(20, 10, 1031, 411));
        Ajouter_5->setCursor(QCursor(Qt::ArrowCursor));
        stat->addTab(tab_5, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 10, 521, 61));
        label->setStyleSheet(QLatin1String("color: rgb(96, 23, 0);\n"
"font: 26pt \"Sitka\";"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 26));
        menuGESTION_DES_CLIENTS = new QMenu(menuBar);
        menuGESTION_DES_CLIENTS->setObjectName(QStringLiteral("menuGESTION_DES_CLIENTS"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGESTION_DES_CLIENTS->menuAction());

        retranslateUi(MainWindow);

        stat->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        stat->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Ajouter->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tel->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phone", Q_NULLPTR));
        type->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        rb1->setText(QApplication::translate("MainWindow", "Etudiant(e)", Q_NULLPTR));
        rb2->setText(QApplication::translate("MainWindow", "Fonctionnaire", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nombre de visite", Q_NULLPTR));
        cin->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        nom->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        prenom->setText(QApplication::translate("MainWindow", "Pr\303\251nom", Q_NULLPTR));
        date_naisc->setText(QApplication::translate("MainWindow", "Date de naissance ", Q_NULLPTR));
        adresse->setText(QApplication::translate("MainWindow", "Adresse-mail", Q_NULLPTR));
        b_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        Ajouter_3->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        cin_3->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        nom_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        prenom_2->setText(QApplication::translate("MainWindow", "Pr\303\251nom", Q_NULLPTR));
        date_naisc_2->setText(QApplication::translate("MainWindow", "Date de naissance ", Q_NULLPTR));
        tel_2->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phone", Q_NULLPTR));
        adresse_2->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        b_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        type_3->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        rb1_3->setText(QApplication::translate("MainWindow", "Etudiant(e)", Q_NULLPTR));
        rb2_3->setText(QApplication::translate("MainWindow", "Fonctionnaire", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab_3), QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tri->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Tri par CIN</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tri->setText(QApplication::translate("MainWindow", "Tri par nom", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        stat_2->setText(QApplication::translate("MainWindow", "Stat", Q_NULLPTR));
        fd->setText(QApplication::translate("MainWindow", "Client Fid\303\250le", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        b_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        cin_2->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab_4), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        envoyer->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Envoyer</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        envoyer->setText(QApplication::translate("MainWindow", "Envoyer", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:9pt;\">Adresse-mail :</span></p></body></html>", Q_NULLPTR));
        textEdit_5->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">Sujet :</span></p></body></html>", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">Message :</span></p></body></html>", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab_6), QApplication::translate("MainWindow", "Mailing", Q_NULLPTR));
        Ajouter_5->setTitle(QApplication::translate("MainWindow", "Client fid\303\250le", Q_NULLPTR));
        stat->setTabText(stat->indexOf(tab_5), QApplication::translate("MainWindow", "Client fid\303\250le", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "GESTION DES CLIENTS", Q_NULLPTR));
        menuGESTION_DES_CLIENTS->setTitle(QApplication::translate("MainWindow", "GESTION DES CLIENTS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
