/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *table_screen;
    QPushButton *navigate_add_table;
    QPushButton *navigate_czw;
    QPushButton *navigate_pt;
    QPushButton *navigate_sb;
    QPushButton *navigate_niedz;
    QPushButton *start_plus_table;
    QPushButton *start_minus_table;
    QPushButton *navigate_wt;
    QPushButton *navigate_sr;
    QPushButton *navigate_pon;
    QWidget *task_screen;
    QPushButton *navigate_add_tasks;
    QPushButton *start_minus_task;
    QPushButton *start_plus_task;
    QWidget *insert_to_tasks;
    QTextEdit *description_tasks;
    QLineEdit *name_tasks;
    QDateEdit *date_tasks;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *add_to_tasks;
    QPushButton *edit_task;
    QComboBox *color_task;
    QLabel *label_9;
    QWidget *insert_to_notes;
    QTextEdit *description_notes;
    QLabel *label_7;
    QPushButton *add_to_notes;
    QPushButton *edit_note;
    QWidget *notes_screen;
    QPushButton *navigate_add_notes;
    QPushButton *start_minus_note;
    QPushButton *start_plus_note;
    QWidget *insert_to_table;
    QLineEdit *name_table;
    QLineEdit *description_table;
    QLabel *label;
    QLabel *label_2;
    QPushButton *add_to_table;
    QLabel *label_3;
    QTimeEdit *date_table;
    QPushButton *edit_table;
    QComboBox *color_table;
    QLabel *label_8;
    QPushButton *navigate_table;
    QPushButton *navigate_tasks;
    QPushButton *navigate_notes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(665, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 50, 661, 651));
        table_screen = new QWidget();
        table_screen->setObjectName("table_screen");
        navigate_add_table = new QPushButton(table_screen);
        navigate_add_table->setObjectName("navigate_add_table");
        navigate_add_table->setGeometry(QRect(510, 590, 151, 61));
        navigate_add_table->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        navigate_czw = new QPushButton(table_screen);
        navigate_czw->setObjectName("navigate_czw");
        navigate_czw->setGeometry(QRect(273, 1, 95, 30));
        navigate_czw->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
"border-bottom-left-radius:5px;\n"
""));
        navigate_pt = new QPushButton(table_screen);
        navigate_pt->setObjectName("navigate_pt");
        navigate_pt->setGeometry(QRect(367, 1, 95, 30));
        navigate_pt->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
"border-bottom-left-radius:5px;\n"
""));
        navigate_sb = new QPushButton(table_screen);
        navigate_sb->setObjectName("navigate_sb");
        navigate_sb->setGeometry(QRect(460, 1, 101, 30));
        navigate_sb->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
"border-bottom-left-radius:5px;\n"
""));
        navigate_niedz = new QPushButton(table_screen);
        navigate_niedz->setObjectName("navigate_niedz");
        navigate_niedz->setGeometry(QRect(560, 1, 101, 30));
        navigate_niedz->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: none;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-bottom-left-radius:5px;\n"
""));
        start_plus_table = new QPushButton(table_screen);
        start_plus_table->setObjectName("start_plus_table");
        start_plus_table->setGeometry(QRect(310, 610, 40, 40));
        start_plus_table->setStyleSheet(QString::fromUtf8("image: url(icons/down.png);\n"
"border: none;"));
        start_minus_table = new QPushButton(table_screen);
        start_minus_table->setObjectName("start_minus_table");
        start_minus_table->setGeometry(QRect(310, 40, 40, 40));
        start_minus_table->setStyleSheet(QString::fromUtf8("image: url(icons/up.png);;\n"
"border:none;\n"
""));
        navigate_wt = new QPushButton(table_screen);
        navigate_wt->setObjectName("navigate_wt");
        navigate_wt->setGeometry(QRect(90, 1, 95, 30));
        navigate_wt->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
"border-bottom-left-radius:5px;\n"
""));
        navigate_sr = new QPushButton(table_screen);
        navigate_sr->setObjectName("navigate_sr");
        navigate_sr->setGeometry(QRect(180, 1, 95, 30));
        navigate_sr->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
"border-bottom-left-radius:5px;\n"
""));
        navigate_pon = new QPushButton(table_screen);
        navigate_pon->setObjectName("navigate_pon");
        navigate_pon->setGeometry(QRect(-10, 1, 101, 30));
        navigate_pon->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: none;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
"border-bottom-right-radius:5px;\n"
""));
        stackedWidget->addWidget(table_screen);
        task_screen = new QWidget();
        task_screen->setObjectName("task_screen");
        navigate_add_tasks = new QPushButton(task_screen);
        navigate_add_tasks->setObjectName("navigate_add_tasks");
        navigate_add_tasks->setGeometry(QRect(510, 590, 151, 61));
        navigate_add_tasks->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        start_minus_task = new QPushButton(task_screen);
        start_minus_task->setObjectName("start_minus_task");
        start_minus_task->setGeometry(QRect(310, 40, 40, 40));
        start_minus_task->setStyleSheet(QString::fromUtf8("image: url(icons/up.png);\n"
"border:none;\n"
""));
        start_plus_task = new QPushButton(task_screen);
        start_plus_task->setObjectName("start_plus_task");
        start_plus_task->setGeometry(QRect(310, 610, 40, 40));
        start_plus_task->setStyleSheet(QString::fromUtf8("image: url(icons/down.png);\n"
"border:none;\n"
""));
        stackedWidget->addWidget(task_screen);
        insert_to_tasks = new QWidget();
        insert_to_tasks->setObjectName("insert_to_tasks");
        description_tasks = new QTextEdit(insert_to_tasks);
        description_tasks->setObjectName("description_tasks");
        description_tasks->setGeometry(QRect(200, 70, 271, 81));
        description_tasks->setStyleSheet(QString::fromUtf8("border: 2px dotted black;\n"
"background-color: rgb(192,192,192);\n"
"font-size: 20px;"));
        name_tasks = new QLineEdit(insert_to_tasks);
        name_tasks->setObjectName("name_tasks");
        name_tasks->setGeometry(QRect(200, 20, 271, 28));
        name_tasks->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"font-size: 20px;"));
        name_tasks->setMaxLength(29);
        date_tasks = new QDateEdit(insert_to_tasks);
        date_tasks->setObjectName("date_tasks");
        date_tasks->setGeometry(QRect(170, 180, 131, 29));
        date_tasks->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"color: balck;\n"
"font-size: 20px;"));
        label_4 = new QLabel(insert_to_tasks);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 10, 71, 31));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        label_5 = new QLabel(insert_to_tasks);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 70, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        label_6 = new QLabel(insert_to_tasks);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(85, 175, 71, 41));
        label_6->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        add_to_tasks = new QPushButton(insert_to_tasks);
        add_to_tasks->setObjectName("add_to_tasks");
        add_to_tasks->setGeometry(QRect(240, 220, 151, 61));
        add_to_tasks->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        edit_task = new QPushButton(insert_to_tasks);
        edit_task->setObjectName("edit_task");
        edit_task->setGeometry(QRect(240, 290, 151, 61));
        edit_task->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        color_task = new QComboBox(insert_to_tasks);
        color_task->addItem(QString());
        color_task->addItem(QString());
        color_task->addItem(QString());
        color_task->addItem(QString());
        color_task->addItem(QString());
        color_task->addItem(QString());
        color_task->setObjectName("color_task");
        color_task->setGeometry(QRect(430, 180, 171, 31));
        color_task->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"color: balck;\n"
"font-size: 20px;"));
        label_9 = new QLabel(insert_to_tasks);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(330, 180, 91, 31));
        label_9->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        stackedWidget->addWidget(insert_to_tasks);
        insert_to_notes = new QWidget();
        insert_to_notes->setObjectName("insert_to_notes");
        description_notes = new QTextEdit(insert_to_notes);
        description_notes->setObjectName("description_notes");
        description_notes->setGeometry(QRect(160, 60, 341, 211));
        description_notes->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,204);\n"
"border: 3px dotted black;\n"
"font-size:20px;"));
        label_7 = new QLabel(insert_to_notes);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(160, 10, 141, 51));
        label_7->setStyleSheet(QString::fromUtf8("font-size: 23px;\n"
"color: balck;"));
        add_to_notes = new QPushButton(insert_to_notes);
        add_to_notes->setObjectName("add_to_notes");
        add_to_notes->setGeometry(QRect(250, 280, 151, 61));
        add_to_notes->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        edit_note = new QPushButton(insert_to_notes);
        edit_note->setObjectName("edit_note");
        edit_note->setGeometry(QRect(250, 340, 151, 61));
        edit_note->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        stackedWidget->addWidget(insert_to_notes);
        notes_screen = new QWidget();
        notes_screen->setObjectName("notes_screen");
        navigate_add_notes = new QPushButton(notes_screen);
        navigate_add_notes->setObjectName("navigate_add_notes");
        navigate_add_notes->setGeometry(QRect(510, 590, 151, 61));
        navigate_add_notes->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        start_minus_note = new QPushButton(notes_screen);
        start_minus_note->setObjectName("start_minus_note");
        start_minus_note->setGeometry(QRect(10, 335, 40, 40));
        start_minus_note->setStyleSheet(QString::fromUtf8("image: url(icons/left.png);\n"
"border:none;\n"
""));
        start_plus_note = new QPushButton(notes_screen);
        start_plus_note->setObjectName("start_plus_note");
        start_plus_note->setGeometry(QRect(600, 335, 40, 40));
        start_plus_note->setStyleSheet(QString::fromUtf8("image: url(icons/right.png);\n"
"border:none;\n"
""));
        stackedWidget->addWidget(notes_screen);
        insert_to_table = new QWidget();
        insert_to_table->setObjectName("insert_to_table");
        name_table = new QLineEdit(insert_to_table);
        name_table->setObjectName("name_table");
        name_table->setGeometry(QRect(200, 20, 271, 28));
        name_table->setMaximumSize(QSize(271, 28));
        name_table->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"font-size: 20px;"));
        name_table->setMaxLength(29);
        description_table = new QLineEdit(insert_to_table);
        description_table->setObjectName("description_table");
        description_table->setGeometry(QRect(200, 70, 271, 81));
        description_table->setStyleSheet(QString::fromUtf8("border: 2px dotted black;\n"
"background-color: rgb(192,192,192);\n"
"font-size: 20px;"));
        description_table->setMaxLength(44);
        label = new QLabel(insert_to_table);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 10, 71, 51));
        label->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        label_2 = new QLabel(insert_to_table);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 70, 51, 41));
        label_2->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        add_to_table = new QPushButton(insert_to_table);
        add_to_table->setObjectName("add_to_table");
        add_to_table->setGeometry(QRect(240, 220, 151, 61));
        add_to_table->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        label_3 = new QLabel(insert_to_table);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 170, 91, 51));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        date_table = new QTimeEdit(insert_to_table);
        date_table->setObjectName("date_table");
        date_table->setGeometry(QRect(170, 180, 118, 29));
        date_table->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"color: balck;\n"
"font-size: 20px;"));
        edit_table = new QPushButton(insert_to_table);
        edit_table->setObjectName("edit_table");
        edit_table->setGeometry(QRect(240, 290, 151, 61));
        edit_table->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"border: none;"));
        color_table = new QComboBox(insert_to_table);
        color_table->addItem(QString());
        color_table->addItem(QString());
        color_table->addItem(QString());
        color_table->addItem(QString());
        color_table->addItem(QString());
        color_table->addItem(QString());
        color_table->setObjectName("color_table");
        color_table->setGeometry(QRect(430, 180, 171, 31));
        color_table->setStyleSheet(QString::fromUtf8("border-left-style: none;\n"
"border-right-style: none;\n"
"border-top-style: none;\n"
"border-bottom-style: dotted;\n"
"border-bottom-width: 2px;\n"
"background-color: rgb(192,192,192);\n"
"color: balck;\n"
"font-size: 20px;"));
        label_8 = new QLabel(insert_to_table);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(330, 175, 101, 41));
        label_8->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"color: black;"));
        stackedWidget->addWidget(insert_to_table);
        navigate_table = new QPushButton(centralwidget);
        navigate_table->setObjectName("navigate_table");
        navigate_table->setGeometry(QRect(1, 0, 221, 50));
        navigate_table->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"font-style: italic;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-left-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
""));
        navigate_tasks = new QPushButton(centralwidget);
        navigate_tasks->setObjectName("navigate_tasks");
        navigate_tasks->setGeometry(QRect(220, 0, 221, 50));
        navigate_tasks->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"font-style: italic;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-left-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
""));
        navigate_notes = new QPushButton(centralwidget);
        navigate_notes->setObjectName("navigate_notes");
        navigate_notes->setGeometry(QRect(440, 0, 221, 50));
        navigate_notes->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"font-style: italic;\n"
"color: black;\n"
"border-top-style: none;\n"
"border-right-style: solid;\n"
"border-left-style: solid;\n"
"border-bottom-style: solid;\n"
"border-bottom-width: 2px;\n"
"border-left-width: 2px;\n"
"border-right-width: 2px;\n"
"border-bottom-color: black;\n"
"border-left-color: black;\n"
"border-right-color: black;\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        navigate_add_table->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        navigate_czw->setText(QCoreApplication::translate("MainWindow", "Czwartek", nullptr));
        navigate_pt->setText(QCoreApplication::translate("MainWindow", "Pi\304\205tek", nullptr));
        navigate_sb->setText(QCoreApplication::translate("MainWindow", "Sobota", nullptr));
        navigate_niedz->setText(QCoreApplication::translate("MainWindow", "Niedziela", nullptr));
        start_plus_table->setText(QString());
        start_minus_table->setText(QString());
        navigate_wt->setText(QCoreApplication::translate("MainWindow", "Wtorek", nullptr));
        navigate_sr->setText(QCoreApplication::translate("MainWindow", "\305\232roda", nullptr));
        navigate_pon->setText(QCoreApplication::translate("MainWindow", "Poniedzialek", nullptr));
        navigate_add_tasks->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        start_minus_task->setText(QString());
        start_plus_task->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Nazwa:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Opis:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Termin:", nullptr));
        add_to_tasks->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        edit_task->setText(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        color_task->setItemText(0, QCoreApplication::translate("MainWindow", "Niebieski", nullptr));
        color_task->setItemText(1, QCoreApplication::translate("MainWindow", "Fioletowy", nullptr));
        color_task->setItemText(2, QCoreApplication::translate("MainWindow", "Pomara\305\204czowy", nullptr));
        color_task->setItemText(3, QCoreApplication::translate("MainWindow", "Zielony", nullptr));
        color_task->setItemText(4, QCoreApplication::translate("MainWindow", "Czerwony", nullptr));
        color_task->setItemText(5, QCoreApplication::translate("MainWindow", "\305\273\303\263\305\202ty", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Kolor t\305\202a:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Tre\305\233\304\207 notatki:", nullptr));
        add_to_notes->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        edit_note->setText(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        navigate_add_notes->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        start_minus_note->setText(QString());
        start_plus_note->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Nazwa: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Opis: ", nullptr));
        add_to_table->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Godzina:", nullptr));
        edit_table->setText(QCoreApplication::translate("MainWindow", "Edytuj", nullptr));
        color_table->setItemText(0, QCoreApplication::translate("MainWindow", "Niebieski", nullptr));
        color_table->setItemText(1, QCoreApplication::translate("MainWindow", "Fioletowy", nullptr));
        color_table->setItemText(2, QCoreApplication::translate("MainWindow", "Pomara\305\204czowy", nullptr));
        color_table->setItemText(3, QCoreApplication::translate("MainWindow", "\305\273\303\263\305\202ty", nullptr));
        color_table->setItemText(4, QCoreApplication::translate("MainWindow", "Czerwony", nullptr));
        color_table->setItemText(5, QCoreApplication::translate("MainWindow", "Zielony", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Kolor t\305\202a:", nullptr));
        navigate_table->setText(QCoreApplication::translate("MainWindow", "Plan", nullptr));
        navigate_tasks->setText(QCoreApplication::translate("MainWindow", "Zadania", nullptr));
        navigate_notes->setText(QCoreApplication::translate("MainWindow", "Notatki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
