#include <fstream>
#include <iostream>

#include <QApplication>
#include <QTableWidgetItem>
#include <memory>
#include <qboxlayout.h>
#include <qtablewidget.h>
#include "View.hpp"
#include "TaskSerializer.hpp"

ListView::ListView(TaskClient* tc, QWidget *parent) :
    client(tc), QMainWindow(parent)
{
    create_widgets();
    configure_widgets();
    connect_slots();

    sync_with_model();
}

void ListView::create_widgets() {
    add_leaf_button = new QPushButton("add leaf", this);
    add_composite_button = new QPushButton("add composite", this);
    delete_button = new QPushButton("delete", this);
    edit_button = new QPushButton("edit cell", this);

    move_to_button = new QPushButton("move to", this);
    move_up_button = new QPushButton("move up", this);

    quit_button = new QPushButton("quit", this);
    save_and_quit_button = new QPushButton("save and quit", this);

    table = new QTableWidget();
    line = new QLineEdit(this);
}

void ListView::configure_widgets() {
    lay_widgets_out();

    table->setColumnCount(1);
}

void ListView::lay_widgets_out() {
    QHBoxLayout* upper = new QHBoxLayout(this);
    upper->addWidget(add_leaf_button);
    upper->addWidget(add_composite_button);
    upper->addWidget(edit_button);
    upper->addWidget(line);
    upper->addWidget(delete_button);
    upper->addWidget(move_to_button);
    upper->addWidget(move_up_button);

    QHBoxLayout* quitter = new QHBoxLayout(this);
    quitter->addWidget(quit_button);
    quitter->addWidget(save_and_quit_button);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addLayout(upper);
    main_layout->addWidget(table);
    main_layout->addLayout(quitter);


    QWidget* main_widget = new QWidget(this);
    main_widget->setLayout(main_layout);

    this->setCentralWidget(main_widget);
}

void ListView::connect_slots() {
    connect(add_leaf_button, SIGNAL(clicked()),
            this, SLOT(on_add_leaf_clicked()));

    connect(add_composite_button, SIGNAL(clicked()),
            this, SLOT(on_add_composite_clicked()));

    connect(delete_button, SIGNAL(clicked()),
            this, SLOT(on_delete_clicked()));

    connect(edit_button, SIGNAL(clicked()),
            this, SLOT(on_edit_clicked()));


    connect(move_to_button, SIGNAL(clicked()),
            this, SLOT(on_move_to_clicked()));

    connect(move_up_button, SIGNAL(clicked()),
            this, SLOT(on_move_up_clicked()));


    connect(quit_button, SIGNAL(clicked()),
            this, SLOT(on_quit_clicked()));

    connect(save_and_quit_button, SIGNAL(clicked()),
            this, SLOT(on_save_and_quit_clicked()));
}

// update methods
void ListView::sync_with_model() {
    int l = client->curr_children_list().size();
    table->setRowCount(l);
    for(int i = 0; i<l; ++i) {
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(client->get_child(i)->get_name())));
    }
}

// slots
// update contents
void ListView::on_add_leaf_clicked() {
    // ask controller to update
    client->add_leaf(line->text().toStdString());
    line->clear();
    sync_with_model();
}

void ListView::on_add_composite_clicked() {
    // ask controller to update
    client->add_composite(line->text().toStdString());
    line->clear();
    sync_with_model();
}

void ListView::on_delete_clicked() {
    if(table->selectedItems().size()) {
        client->remove_child(table->selectedItems()[0]->row());
        sync_with_model();
    }
    else {
        std::cerr<<"no items selected, cannot delete"<<std::endl;
    }
}

void ListView::on_edit_clicked() {
    if(table->selectedItems().size()) {
        int selected_index = table->selectedItems()[0]->row();
        std::string new_text = line->text().toStdString();
        client->get_child(selected_index)->set_name(new_text);
        line->clear();
        
        sync_with_model();
    }
    else {
        std::cerr<<"no items selected, cannot edit";
    }
}

// move around the tree
void ListView::on_move_to_clicked() {
    client->go_to_child(table->selectedItems()[0]->row());
    sync_with_model();
}

void ListView::on_move_up_clicked() {
    client->go_up();
    sync_with_model();
}

// die
void ListView::on_quit_clicked() {
    std::cout<<"goodbye";
    QApplication::instance()->quit();
}

void ListView::on_save_and_quit_clicked() {
    std::ofstream ofs("task.save", std::ios::trunc);
    client->write(ofs);
    ofs.close();
    on_quit_clicked();
}

ListView::~ListView() = default;
