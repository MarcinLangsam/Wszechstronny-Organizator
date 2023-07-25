#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    this->setFixedSize(665,720);
    connect_to_database();
    setup_database_first_time();

    ui->edit_table->hide();
    ui->edit_task->hide();
    ui->edit_note->hide();

    QPixmap add_map("icons/add.png");
    QIcon add_icon(add_map);
    ui->add_to_table->setIcon(add_icon);
    ui->add_to_table->setIconSize(add_map.rect().size());

    ui->edit_table->setIcon(add_icon);
    ui->edit_table->setIconSize(add_map.rect().size());

    ui->add_to_tasks->setIcon(add_icon);
    ui->add_to_tasks->setIconSize(add_map.rect().size());

    ui->edit_task->setIcon(add_icon);
    ui->edit_task->setIconSize(add_map.rect().size());


    ui->add_to_notes->setIcon(add_icon);
    ui->add_to_notes->setIconSize(add_map.rect().size());

    ui->edit_note->setIcon(add_icon);
    ui->edit_note->setIconSize(add_map.rect().size());

    ui->navigate_add_table->setIcon(add_icon);
    ui->navigate_add_table->setIconSize(add_map.rect().size());


    ui->navigate_add_tasks->setIcon(add_icon);
    ui->navigate_add_tasks->setIconSize(add_map.rect().size());


    ui->navigate_add_notes->setIcon(add_icon);
    ui->navigate_add_notes->setIconSize(add_map.rect().size());

    QPixmap table_map("icons/table.png");
    QIcon table_icon(table_map);
    ui->navigate_table->setIcon(table_icon);
    ui->navigate_table->setIconSize(table_map.rect().size());

    QPixmap task_map("icons/task.png");
    QIcon task_icon(task_map);
    ui->navigate_tasks->setIcon(task_icon);
    ui->navigate_tasks->setIconSize(task_map.rect().size());

    QPixmap note_map("icons/note.png");
    QIcon note_icon(note_map);
    ui->navigate_notes->setIcon(note_icon);
    ui->navigate_notes->setIconSize(note_map.rect().size());

}

void MainWindow::error_message(QString title, QString description)
{
    QMessageBox errorBox;
    errorBox.critical(0,title,description);
    errorBox.setFixedSize(500,200);
}
void MainWindow::connect_to_database()
{
    db.setDatabaseName("baza.db");
    db.open();
    if(db.open()){}
    else { error_message("Błąd bazy dancyh","Nie udało się połączyć z bazą dancy.\nUpewnij się, że jest ona nazwana poprwanie.\nDomyślan nazwa: <b>baza.db</b>"); }
}
void MainWindow::setup_database_first_time()
{
    QString table_pon = "CREATE TABLE poniedzialek(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT)";
    QString table_wt = "CREATE TABLE wtorek(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_sr = "CREATE TABLE sroda(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_czw = "CREATE TABLE czwartek(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_pt = "CREATE TABLE piatek(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_sob = "CREATE TABLE sobota(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_niedz = "CREATE TABLE niedziela(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_zadania = "CREATE TABLE zadania(ID integer PRIMARY KEY AUTOINCREMENT, nazwa TEXT, opis TEXT, godzina DATETIME, kolor TEXT);";
    QString table_notatki = "CREATE TABLE notatki(ID integer PRIMARY KEY AUTOINCREMENT, tresc TEXT);";

    query->exec(table_pon);
    query->exec(table_wt);
    query->exec(table_sr);
    query->exec(table_czw);
    query->exec(table_pt);
    query->exec(table_sob);
    query->exec(table_niedz);
    query->exec(table_zadania);
    query->exec(table_notatki);
}
void MainWindow::insert_to_table_or_tasks(QString table_name, QString name, QString description, QString date, QString color)
{
    QString insert = "INSERT INTO " + table_name + "(ID,nazwa,opis,godzina,kolor) VALUES(NULL,'" + name + "','" + description +"','"+ date+"','"+color+"');";

    if(query->exec(insert)){}
    else { error_message("Błąd dodawania","Wystąpił błąd podczas dodawania do bazy danych\nSpróbuj ponownie."); }
}

void MainWindow::insert_to_notes(QString note)
{
    QString insert = "INSERT INTO notatki (ID,tresc) VALUES(NULL,'" + note + "');";

    if(query->exec(insert)) {}
    else { error_message("Błąd dodawania","Wystąpił błąd podczas dodawania do bazy danych\nSpróbuj ponownie."); }
}

void MainWindow::delete_record(int index)
{
    if(ui->stackedWidget->currentIndex() == 0) //tablica
    {
        delete_from_table_or_tasks(current_day,QString::number(index));
        show_table_or_task_by_day(current_day);
    }

    if(ui->stackedWidget->currentIndex() == 1) //zadania
    {
        delete_from_table_or_tasks("zadania",QString::number(index));
        show_table_or_task_by_day("zadania");
    }
    if(ui->stackedWidget->currentIndex() == 4) //notatki
    {
        delete_from_notes(QString::number(index));
        show_notes();
    }

}

void MainWindow::edit_record(int index, int count)
{
    index_for_edit = index;
    if(ui->stackedWidget->currentIndex() == 0) //tablica
    {
        clear();
        ui->edit_table->show();
        ui->add_to_table->hide();
        fill_textboxes(count);
        ui->stackedWidget->setCurrentIndex(5);

    }
    if(ui->stackedWidget->currentIndex() == 1) //zadania
    {
        clear();
        ui->edit_task->show();
        ui->add_to_tasks->hide();
        fill_textboxes(count);
        ui->stackedWidget->setCurrentIndex(2);
    }
    if(ui->stackedWidget->currentIndex() == 4) //notatki
    {
        clear();
        ui->edit_note->show();
        ui->add_to_notes->hide();
        fill_textboxes(count);
        ui->stackedWidget->setCurrentIndex(3);
    }
}

void MainWindow::delete_from_table_or_tasks(QString table_name, QString index)
{
    QString erase = "DELETE FROM "+table_name+" WHERE ID="+index+";";
    if(query->exec(erase)) {}
    else { error_message("Błąd usuwania","Wystąpił błąd podczas usuwania z bazy danych\nSpróbuj ponownie."); }
}

void MainWindow::delete_from_notes(QString index)
{
    QString erase = "DELETE FROM notatki WHERE ID="+index+";";
    if(query->exec(erase)) {}
    else { error_message("Błąd usuwania","Wystąpił błąd podczas usuwania z bazy danych\nSpróbuj ponownie."); }
}

void MainWindow::edit_table_or_tasks(QString table_name, QString index)
{
    if(ui->stackedWidget->currentIndex() == 5)
    {
        QString edit= "UPDATE "+table_name+" SET nazwa='"+ui->name_table->text()+"', opis='"+ui->description_table->text()+"', godzina='"+ui->date_table->text()+"', kolor='"+ui->color_table->currentText()+"' WHERE ID="+index+";";
        if(query->exec(edit)) {}
        else { error_message("Błąd edycji","Wystąpił błąd podczas edytowania bazy danych\nSpróbuj ponownie."); }
    }

    if(ui->stackedWidget->currentIndex()== 2)
    {
        QString edit= "UPDATE "+table_name+" SET nazwa='"+ui->name_tasks->text()+"', opis='"+ui->description_tasks->toPlainText()+"', godzina='"+ui->date_tasks->text()+"', kolor='"+ui->color_task->currentText()+"' WHERE ID="+index+";";
        if(query->exec(edit)) {}
        else { error_message("Błąd edycji","Wystąpił błąd podczas edytowania bazy danych\nSpróbuj ponownie."); }
    }
}

void MainWindow::edit_notes(QString index)
{
    QString edit = "UPDATE notatki SET tresc='"+ui->description_notes->toPlainText()+"' WHERE ID="+index+";";
    if(query->exec(edit)) {}
    else { error_message("Błąd edycji","Wystąpił błąd podczas edytowania bazy danych\nSpróbuj ponownie."); }
}

QColor MainWindow::get_color(QString color_text)
{
    QColor color;
    if(color_text == "Niebieski"){color = QColor(0,128,255);}
    if(color_text == "Czerwony"){color = QColor(255,51,51);}
    if(color_text == "Zielony"){color = QColor(51,255,51);}
    if(color_text == "Żółty"){color = QColor(255,255,102);}
    if(color_text == "Fioletowy"){color = QColor(153,51,255);}
    if(color_text == "Pomarańczowy"){color = QColor(255,153,51);}
    if(color_text == "Notka"){color = QColor(255,255,204);}
    return color;
}

void MainWindow::show_table_or_task_by_day(QString table_name)
{
    QFont date_font("Arial", 23, QFont::Bold);
    QFont date_font_task("Arial", 16, QFont::Bold);
    QFont name_font("Arial", 16);
    QFont description_font("Arial", 10);
    QString show = "SELECT * FROM " + table_name + " ORDER BY godzina;";
    QString name;
    QString description;
    QString date;
    QString date_task;
    QString color;
    int count = 0;
    int records_count = 2;
    int index = 1;
    QPalette pal = QPalette();
    QPixmap complete_map("icons/complete.png");
    QIcon complete_icon(complete_map);

    hide_records();

    if(query->exec(show))
    {
        while (query->next()) {
            QSqlRecord record = query->record();
            name = record.value(1).toString();
            description = record.value(2).toString();
            QDate time = QDate::currentDate();
            int deadline;
            QString formattedTime = time.toString("dd.MM.yyyy");
            deadline = time.daysTo(QDate::fromString(record.value(3).toString(),"dd.MM.yyyy"));
            date = record.value(3).toString();
            if(deadline<0) date_task = formattedTime+" - "+record.value(3).toString()+"\nPO TERMINIE!";
            else if(deadline == 0) date_task = formattedTime+" - "+record.value(3).toString()+"\nDeadline: Dziś!";
            else date_task = formattedTime+" - "+record.value(3).toString()+"\nDeadline za: "+QString::number(deadline)+" dni!";

            color = record.value(4).toString();
            index = record.value(0).toInt();

            QWidget *widget = new QWidget(this);
            pal.setColor(QPalette::Window, get_color(color));
            widget->setAutoFillBackground(true);
            widget->setPalette(pal);

            QLabel *label_n = new QLabel(this);
            label_n->setText(name);
            label_n->setFont(name_font);
            QLabel *label_des = new QLabel(this);
            label_des->setText(description);
            label_des->setFont(description_font);
            QLabel *label_d = new QLabel(this);
            label_d->setText(date);
            label_d->setFont(date_font);

            QPushButton *button_del = new QPushButton(this);
            QPixmap del_map("icons/delete.png");
            QIcon del_icon(del_map);
            button_del->setIcon(del_icon);
            button_del->setIconSize(del_map.rect().size());
            button_del->setStyleSheet(buttonStyle);
            button_del->setToolTip("Usuń rekord\\Zakończ zadanie");
            connect(button_del, &QPushButton::released, this, [this, index](){delete_record(index);});


            QPushButton *button_edit = new QPushButton(this);
            button_edit->setStyleSheet(buttonStyle);
            QPixmap edit_map("icons/edit.png");
            QIcon edit_icon(edit_map);
            button_edit->setIcon(edit_icon);
            button_edit->setIconSize(edit_map.rect().size());
            button_edit->setStyleSheet(buttonStyle);
            button_edit->setToolTip("Edytuj rekord");
            connect(button_edit, &QPushButton::released, this, [this, index, count](){edit_record(index,count);});

            if(ui->stackedWidget->currentIndex() == 0)
            {
                table.push_back({widget,label_n,label_des,label_d,button_del,button_edit,get_color(color)});
            }

            if(ui->stackedWidget->currentIndex() == 1)
            {
                label_d->setText(date_task);
                label_d->setFont(date_font_task);
                tasks.push_back({widget,label_n,label_des,label_d,button_del,button_edit,get_color(color)});
            }
            count++;
        }

        if (ui->stackedWidget->currentIndex() == 0)
        {
            count = 0;
            if(start_for_objects+6>table.length()-1){records_count = table.length()-1;}
            else{records_count = start_for_objects+6;}

            for(int i=start_for_objects;i<=records_count;i++)
            {
                table[i].record->setGeometry(10,140+count*66,640,65);
                table[i].record->show();

                table[i].record_name->setGeometry(105,140+count*66,450,30);
                table[i].record_name->show();

                table[i].record_description->setGeometry(105,175+count*65,450,30);
                table[i].record_description->show();

                table[i].record_date->setGeometry(15,150+count*65,85,40);
                table[i].record_date->show();

                table[i].record_del->setGeometry(580,160+count*65,30,30);
                table[i].record_del->show();

                table[i].record_edit->setGeometry(616,160+count*65,30,30);
                table[i].record_edit->show();

                count++;
            }
        }

        if (ui->stackedWidget->currentIndex() == 1)
        {
            count = 0;
            if(start_for_objects+6>tasks.length()-1){records_count = tasks.length()-1;}
            else{records_count = start_for_objects+6;}

            for(int i=start_for_objects;i<=records_count;i++)
            {
                tasks[i].record->setGeometry(10,140+count*66,640,65);
                tasks[i].record->show();

                tasks[i].record_name->setGeometry(15,145+count*66,350,30);
                tasks[i].record_name->show();

                tasks[i].record_description->setGeometry(15,175+count*65,350,30);
                tasks[i].record_description->show();

                tasks[i].record_date->setGeometry(340,145+count*65,450,60);
                tasks[i].record_date->show();

                tasks[i].record_del->setGeometry(580,160+count*65,30,30);
                tasks[i].record_del->setIcon(complete_icon);
                tasks[i].record_del->setIconSize(complete_map.rect().size());
                tasks[i].record_del->show();

                tasks[i].record_edit->setGeometry(616,160+count*65,30,30);
                tasks[i].record_edit->show();

                count++;
            }
        }
    }
    else { error_message("Błąd bazy dancyh","Wystąpił błąd podczas wyciągania dancyh z bazy\nSpróbuj ponownie."); }
}

void MainWindow::show_notes()
{
    QString show = "SELECT * FROM notatki;";
    QString data;
    double count = 0;
    double records_count = 0;
    int index = 1;
    double position_help = 0;
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(255,255,204));

    hide_records();

    if(query->exec(show))
    {
        while (query->next()) {

            QSqlRecord record = query->record();
            data = record.value(1).toString();
            index = record.value(0).toInt();
            QWidget *widget = new QWidget(this);
            widget->setAutoFillBackground(true);
            widget->setPalette(pal);

            QLabel *label_des = new QLabel(this);
            label_des->setText(data);

            QPushButton *button_del = new QPushButton(this);
            QPixmap del_map("icons/delete.png");
            QIcon del_icon(del_map);
            button_del->setIcon(del_icon);
            button_del->setIconSize(del_map.rect().size());
            button_del->setStyleSheet(buttonStyle);
            button_del->setToolTip("Usuń notatkę");
            connect(button_del, &QPushButton::released, this, [this, index](){delete_record(index);});

            QPushButton *button_edit = new QPushButton(this);
            QPixmap edit_map("icons/edit.png");
            QIcon edit_icon(edit_map);
            button_edit->setIcon(edit_icon);
            button_edit->setIconSize(edit_map.rect().size());
            button_edit->setStyleSheet(buttonStyle);
            button_edit->setToolTip("Edytuj notatkę");
            connect(button_edit, &QPushButton::released, this, [this, index, count](){edit_record(index,count);});

            notes.push_back({widget,NULL,label_des,NULL,button_del,button_edit,get_color("Notka")});
            count++;

        }

        if(start_for_objects+3>notes.length()-1){records_count = notes.length()-1;}
        else{records_count = start_for_objects+3;}
        count = 0;
        for(int i=start_for_objects;i<=records_count;i++)
        {

            if(count == 2){position_help = 280; count =0;}
            notes[i].record->setGeometry(80+count*255,90+position_help,240,230);
            notes[i].record->show();

            notes[i].record_description->setGeometry(85+count*255,90+position_help,240,230);
            notes[i].record_description->show();

            notes[i].record_del->setGeometry(85+count*255,285+position_help,30,30);
            notes[i].record_del->show();

            notes[i].record_edit->setGeometry(120+count*255,285+position_help,30,30);
            notes[i].record_edit->show();
            count++;
        }

    }
    else { error_message("Błąd bazy dancyh","Wystąpił błąd podczas wyciągania dancyh z bazy\nSpróbuj ponownie."); }
}

void MainWindow::hide_records()
{
    if (ui->stackedWidget->currentIndex() == 0)
    {
        for(int i=0;i<table.length();i++)
        {
            table[i].record->hide();
            table[i].record_name->hide();
            table[i].record_description->hide();
            table[i].record_date->hide();
            table[i].record_del->hide();
            table[i].record_edit->hide();
            delete table[i].record;
            delete table[i].record_name;
            delete table[i].record_description;
            delete table[i].record_date;
            delete table[i].record_del;
            delete table[i].record_edit;

        }
        table.clear();
        table.shrink_to_fit();
    }
    if (ui->stackedWidget->currentIndex() == 1)
    {
        for(int i=0;i<tasks.length();i++)
        {
            tasks[i].record->hide();
            tasks[i].record_name->hide();
            tasks[i].record_description->hide();
            tasks[i].record_date->hide();
            tasks[i].record_del->hide();
            tasks[i].record_edit->hide();
            delete tasks[i].record;
            delete tasks[i].record_name;
            delete tasks[i].record_description;
            delete tasks[i].record_date;
            delete tasks[i].record_del;
            delete tasks[i].record_edit;

        }
        tasks.clear();
        tasks.shrink_to_fit();
    }
    if (ui->stackedWidget->currentIndex() == 4)
    {
        for(int i=0;i<notes.length();i++)
        {
            notes[i].record->hide();
            notes[i].record_description->hide();
            notes[i].record_del->hide();
            notes[i].record_edit->hide();
            delete notes[i].record;
            delete notes[i].record_description;
            delete notes[i].record_del;
            delete notes[i].record_edit;

        }
        notes.clear();
        notes.shrink_to_fit();
    }
}

void MainWindow::clear()
{
    if (ui->stackedWidget->currentIndex() == 0)
    {
        for(int i=0;i<table.length();i++)
        {
            table[i].record->hide();
            table[i].record_name->hide();
            table[i].record_description->hide();
            table[i].record_date->hide();
            table[i].record_del->hide();
            table[i].record_edit->hide();

        }
    }
    if (ui->stackedWidget->currentIndex() == 1)
    {
        for(int i=0;i<tasks.length();i++)
        {
            tasks[i].record->hide();
            tasks[i].record_name->hide();
            tasks[i].record_description->hide();
            tasks[i].record_date->hide();
            tasks[i].record_del->hide();
            tasks[i].record_edit->hide();

        }
    }
    if (ui->stackedWidget->currentIndex() == 4)
    {
        for(int i=0;i<notes.length();i++)
        {
            notes[i].record->hide();
            notes[i].record_description->hide();
            notes[i].record_del->hide();
            notes[i].record_edit->hide();
        }
    }
}

MainWindow::~MainWindow()
{   delete ui;  }

void MainWindow::on_navigate_pon_clicked()
{
    start_for_objects = 0;
    current_day = "poniedzialek";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_pon->setStyleSheet(selected_day);
}

void MainWindow::on_navigate_wt_clicked()
{
    start_for_objects = 0;
    current_day = "wtorek";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_wt->setStyleSheet(selected_day);
}
void MainWindow::on_navigate_sr_clicked()
{
    start_for_objects = 0;
    current_day = "sroda";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_sr->setStyleSheet(selected_day);
}
void MainWindow::on_navigate_czw_clicked()
{
    start_for_objects = 0;
    current_day = "czwartek";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_czw->setStyleSheet(selected_day);
}
void MainWindow::on_navigate_pt_clicked()
{
    start_for_objects = 0;
    current_day = "piatek";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_pt->setStyleSheet(selected_day);
}
void MainWindow::on_navigate_sb_clicked()
{
    start_for_objects = 0;
    current_day = "sobota";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_sb->setStyleSheet(selected_day);
}

void MainWindow::on_navigate_niedz_clicked()
{
    start_for_objects = 0;
    current_day = "niedziela";
    show_table_or_task_by_day(current_day);
    ui->stackedWidget->setCurrentIndex(0);
    clear_selected_day();
    ui->navigate_niedz->setStyleSheet(selected_day);
}

void MainWindow::on_navigate_table_clicked()
{ start_for_objects=0; hide_records(); ui->stackedWidget->setCurrentIndex(0); show_table_or_task_by_day(current_day); clear_selected(); ui->navigate_table->setStyleSheet(selected); if(current_day == "poniedzialek"){ui->navigate_pon->setStyleSheet(selected_day);}}

void MainWindow::on_navigate_tasks_clicked()
{ start_for_objects=0; hide_records(); ui->stackedWidget->setCurrentIndex(1); show_table_or_task_by_day("zadania"); clear_selected(); ui->navigate_tasks->setStyleSheet(selected);}

void MainWindow::on_navigate_notes_clicked()
{ start_for_objects=0; hide_records(); ui->stackedWidget->setCurrentIndex(4); show_notes(); clear_selected(); ui->navigate_notes->setStyleSheet(selected);}

void MainWindow::on_navigate_add_table_clicked()
{ hide_records(); ui->stackedWidget->setCurrentIndex(5); clear_textboxes(); }

void MainWindow::on_navigate_add_tasks_clicked()
{ hide_records(); ui->stackedWidget->setCurrentIndex(2); clear_textboxes(); }

void MainWindow::on_navigate_add_notes_clicked()
{ hide_records(); ui->stackedWidget->setCurrentIndex(3); clear_textboxes(); }

void MainWindow::on_add_to_table_clicked()
{
    insert_to_table_or_tasks(current_day,ui->name_table->text(),ui->description_table->text(),ui->date_table->text(),ui->color_table->currentText());
    ui->stackedWidget->setCurrentIndex(0);
    show_table_or_task_by_day(current_day);
}

void MainWindow::on_add_to_tasks_clicked()
{
    insert_to_table_or_tasks("zadania",ui->name_tasks->text(),ui->description_tasks->toPlainText(),ui->date_tasks->text(),ui->color_task->currentText());
    ui->stackedWidget->setCurrentIndex(1);
    show_table_or_task_by_day("zadania");
}

void MainWindow::on_add_to_notes_clicked()
{
    insert_to_notes(ui->description_notes->toPlainText());
    ui->stackedWidget->setCurrentIndex(4);
    show_notes();
}

void MainWindow::on_start_minus_table_clicked()
{
    if(start_for_objects == 0){}
    else {start_for_objects--;}
    show_table_or_task_by_day(current_day);

}

void MainWindow::on_start_plus_table_clicked()
{
    if(table.length() < 7 || start_for_objects > table.length()-2){}
    else {start_for_objects++;}
    show_table_or_task_by_day(current_day);
}

void MainWindow::on_start_minus_task_clicked()
{
    if(start_for_objects == 0){}
    else {start_for_objects--;}
    show_table_or_task_by_day("zadania");
}

void MainWindow::on_start_plus_task_clicked()
{
    if(table.length() < 7 || start_for_objects > table.length()-2){}
    else {start_for_objects++;}
    show_table_or_task_by_day("zadania");
}

void MainWindow::on_start_plus_note_clicked()
{
    if(notes.length() < 4 || start_for_objects > notes.length()-2){}
    else {start_for_objects++;}
    show_notes();
}

void MainWindow::on_start_minus_note_clicked()
{
    if(start_for_objects == 0){}
    else {start_for_objects--;}
    show_notes();
}

void MainWindow::on_edit_table_clicked()
{
    edit_table_or_tasks(current_day,QString::number(index_for_edit));
    ui->edit_table->hide();
    ui->add_to_table->show();
    ui->stackedWidget->setCurrentIndex(0);
    show_table_or_task_by_day(current_day);
}


void MainWindow::on_edit_task_clicked()
{
    edit_table_or_tasks("zadania",QString::number(index_for_edit));
    ui->edit_task->hide();
    ui->add_to_tasks->show();
    ui->stackedWidget->setCurrentIndex(1);
    show_table_or_task_by_day("zadania");
}

void MainWindow::on_edit_note_clicked()
{
    edit_notes(QString::number(index_for_edit));
    ui->edit_note->hide();
    ui->add_to_notes->show();
    ui->stackedWidget->setCurrentIndex(4);
    show_notes();
}

void MainWindow::clear_selected()
{
    ui->navigate_notes->setStyleSheet(deselected);
    ui->navigate_table->setStyleSheet(deselected);
    ui->navigate_tasks->setStyleSheet(deselected);
}

void MainWindow::clear_selected_day()
{
    ui->navigate_pon->setStyleSheet(deselected_day);
    ui->navigate_wt->setStyleSheet(deselected_day);
    ui->navigate_sr->setStyleSheet(deselected_day);
    ui->navigate_czw->setStyleSheet(deselected_day);
    ui->navigate_pt->setStyleSheet(deselected_day);
    ui->navigate_sb->setStyleSheet(deselected_day);
    ui->navigate_niedz->setStyleSheet(deselected_day);
}

void MainWindow::clear_textboxes()
{
    ui->name_table->setText("");
    ui->description_table->setText("");
    ui->name_tasks->setText("");
    ui->description_tasks->setText("");
    ui->description_notes->setText("");
}

void MainWindow::fill_textboxes(int index)
{
    if(ui->stackedWidget->currentIndex() == 0) //tablica
    {
        ui->name_table->setText(table[index].record_name->text());
        ui->description_table->setText(table[index].record_description->text());
    }

    if(ui->stackedWidget->currentIndex() == 1) //zadania
    {
        ui->name_tasks->setText(tasks[index].record_name->text());
        ui->description_tasks->setText(tasks[index].record_description->text());
    }
    if(ui->stackedWidget->currentIndex() == 4) //notatki
    {
        ui->description_notes->setText(notes[index].record_description->text());
    }
}


