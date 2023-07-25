#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include <QScrollArea>
#include <QColor>
#include <QIcon>
#include <QPixmap>
#include <QDate>
#include <QByteArray>
#include <QSystemTrayIcon>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Records
{
    QWidget *record;
    QLabel *record_name;
    QLabel *record_description;
    QLabel *record_date;
    QPushButton *record_del;
    QPushButton *record_edit;
    QColor record_color;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_navigate_pon_clicked();
    void on_navigate_wt_clicked();
    void on_navigate_sr_clicked();
    void on_navigate_czw_clicked();
    void on_navigate_pt_clicked();
    void on_navigate_sb_clicked();
    void on_navigate_niedz_clicked();
    void on_navigate_table_clicked();
    void on_navigate_tasks_clicked();
    void on_navigate_notes_clicked();
    void on_navigate_add_table_clicked();
    void on_navigate_add_tasks_clicked();
    void on_navigate_add_notes_clicked();
    void on_add_to_table_clicked();
    void on_add_to_tasks_clicked();
    void on_add_to_notes_clicked();
    void on_start_minus_table_clicked();
    void on_start_plus_table_clicked();
    void on_start_minus_task_clicked();
    void on_start_plus_task_clicked();
    void on_start_plus_note_clicked();
    void on_start_minus_note_clicked();
    void on_edit_note_clicked();
    void on_edit_table_clicked();
    void on_edit_task_clicked();

private:
    Ui::MainWindow *ui;
    QString current_day = "poniedzialek";
    int start_for_objects = 0;
    int index_for_edit = 0;
    QString buttonStyle = "QPushButton{border:none;background-color:rgba(255, 255, 255,0);}";
    QVector<Records> table;
    QVector<Records> tasks;
    QVector<Records> notes;
    QString deselected = "font-size: 24px; font-style: italic; color: black; border-top-style: none; border-right-style: solid; border-left-style: solid; border-bottom-style: solid; border-bottom-width: 2px; border-left-width: 2px; border-right-width: 2px; border-bottom-color: black; border-left-color: black; border-right-color: black;";
    QString selected = "font-size: 24px; font-style: italic; color: black; border-top-style: none; border-right-style: solid; border-left-style: solid; border-bottom-style: solid; border-bottom-width: 2px; border-left-width: 2px; border-right-width: 2px; border-bottom-color: black; border-left-color: black; border-right-color: black; background-color: rgb(122,122,122);";

    QString deselected_day = "font-size: 14px; color: black; border-top-style: none; border-right-style: solid; border-left-style: none; border-bottom-style: solid; border-bottom-width: 2px; border-right-width: 2px; border-bottom-color: black; border-left-color: black; border-right-color: black; border-bottom-right-radius:5px;";
    QString selected_day = "font-size: 14px; color: black; border-top-style: none; border-right-style: solid; border-left-style: none; border-bottom-style: solid; border-bottom-width: 2px; border-right-width: 2px; border-bottom-color: black; border-left-color: black; border-right-color: black; border-bottom-right-radius:5px;background-color: rgb(122,122,122);";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery *query = new QSqlQuery(db);
    void connect_to_database();
    void setup_database_first_time();
    void insert_to_table_or_tasks(QString table_name, QString name, QString description, QString date, QString color);
    void insert_to_notes(QString note);
    void delete_from_table_or_tasks(QString table_name, QString index);
    void delete_from_notes(QString index);
    void edit_table_or_tasks(QString table_name, QString index);
    void edit_notes(QString index);
    void drop_table(QString table_name);
    void delete_record(int index);
    void edit_record(int index, int count);
    void show_table_or_task_by_day(QString table_name);
    void show_notes();
    void hide_records();
    void clear();
    void clear_selected();
    void clear_selected_day();
    void clear_textboxes();
    void fill_textboxes(int index);
    QColor get_color(QString color_text);
    void error_message(QString title,QString description);

};
#endif // MAINWINDOW_H
