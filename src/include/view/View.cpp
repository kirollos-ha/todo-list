#include <fstream>
#include <iostream>

#include <QApplication>
#include <QApplication>
#include <QTableWidgetItem>
#include <memory>
#include <qboxlayout.h>
#include <qerrormessage.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

#include "TaskComponent.hpp"
#include "TaskDoableChecker.hpp"
#include "View.hpp"
#include "TableRenderer.hpp"
#include "../task/TaskCounter.hpp"
// #include "TaskSerializer.hpp"

ListView::ListView(TaskClient* client, QWidget *parent)
    :QMainWindow(parent), client(client)
{
    create_widgets();
    create_other();
    configure_widgets();
    configure_other();
    connect_slots();
    sync_with_model();
}

void ListView::create_other() {
    nothing_selected_error = new QErrorMessage(this);
    invalid_date_error = new QErrorMessage(this);
    cannot_mark_done_error = new QErrorMessage(this);
    cannot_go_to_leaf_error = new QErrorMessage(this);
}

void ListView::configure_other() {
    return; // al momento niente
}

void ListView::create_widgets() {
    add_leaf_button = new QPushButton("add leaf", this);
    add_composite_button = new QPushButton("add composite", this);
    delete_button = new QPushButton("delete", this);

    edit_name_button = new QPushButton("change name", this);
    edit_description_button = new QPushButton("change description", this);
    edit_date_button = new QPushButton("change date", this);
    mark_done_button = new QPushButton("mark done", this);

    move_to_button = new QPushButton("move to", this);
    move_up_button = new QPushButton("move up", this);

    quit_button = new QPushButton("quit", this);
    save_and_quit_button = new QPushButton("save and quit", this);

    task_count_label = new QLabel("", this);

    task_display_table = new QTableWidget(this);
    task_name = new QLineEdit(this);
    task_description = new QLineEdit(this);
    task_date_selection = new QCalendarWidget(this);
}

void ListView::configure_widgets() {
    lay_widgets_out();
    task_display_table->setColumnCount(3);
}

void ListView::lay_widgets_out() {
    QHBoxLayout* upper = new QHBoxLayout();
    upper->addWidget(add_leaf_button);
    upper->addWidget(add_composite_button);
    upper->addWidget(edit_name_button);
    upper->addWidget(task_name);
    upper->addWidget(delete_button);
    upper->addWidget(move_to_button);
    upper->addWidget(move_up_button);

    QHBoxLayout* midder = new QHBoxLayout();
    midder->addWidget(mark_done_button);
    midder->addWidget(edit_description_button);
    midder->addWidget(task_description);
    midder->addWidget(edit_date_button);
    midder->addWidget(task_date_selection);

    QHBoxLayout* downer = new QHBoxLayout();
    downer->addWidget(quit_button);
    downer->addWidget(save_and_quit_button);

    QWidget* main_widget = new QWidget(this);
    QVBoxLayout* main_layout = new QVBoxLayout(main_widget);
    main_layout->addLayout(upper);
    main_layout->addLayout(midder);
    main_layout->addWidget(task_count_label);
    main_layout->addWidget(task_display_table);
    main_layout->addLayout(downer);

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


    connect(edit_name_button, SIGNAL(clicked()),
            this, SLOT(on_edit_name_clicked()));

    connect(edit_description_button, SIGNAL(clicked()),
            this, SLOT(on_edit_description_clicked()));

    connect(edit_date_button, SIGNAL(clicked()),
            this, SLOT(on_edit_date_clicked()));


    connect(move_to_button, SIGNAL(clicked()),
            this, SLOT(on_move_to_clicked()));

    connect(move_up_button, SIGNAL(clicked()),
            this, SLOT(on_move_up_clicked()));

    connect(mark_done_button, SIGNAL(clicked()),
            this, SLOT(on_mark_done_clicked()));


    connect(quit_button, SIGNAL(clicked()),
            this, SLOT(on_quit_clicked()));

    connect(save_and_quit_button, SIGNAL(clicked()),
            this, SLOT(on_save_and_quit_clicked()));
}

// update methods
void ListView::sync_with_model() {
    TableRenderer tb;
    tb.render_model(client, task_display_table);
    TaskCounter tc;
    for(auto c : client->curr_children_list()) {
        c->accept(&tc);
    }
    std::stringstream label_gen;
    label_gen<<tc.get_total()<<" : total, "
             <<tc.get_done()<<" : done, "
             <<tc.get_todo()<<" : to be done, "
             <<tc.get_overdue()<<" : overdue";
    task_count_label->setText(QString::fromStdString(label_gen.str()));
}

bool ListView::any_selections() {
    return task_display_table->selectedItems().size();
}

int ListView::selected_row() {
    return task_display_table->selectedItems()[0]->row();
}

// slots
// update contents
void ListView::on_add_leaf_clicked() {
    std::string name = task_name->text().toStdString();
    std::string description = task_description->text().toStdString();

    Date due_date = Date::from((int)task_date_selection->selectedDate().day(),
                               (int)task_date_selection->selectedDate().month(),
                               (int)task_date_selection->selectedDate().year());

    if(due_date.is_void()) {
        invalid_date_error->showMessage(QString::fromStdString("date is invalid, cannot add task"));
        return;
    }

    task_name->clear();
    task_description->clear();

    client->add_leaf(name, description, due_date);

    sync_with_model();
}

void ListView::on_add_composite_clicked() {
    // ask controller to update
    std::string name = task_name->text().toStdString();
    std::string description = task_description->text().toStdString();
    Date due_date = Date::from(task_date_selection->selectedDate().day(),
                               task_date_selection->selectedDate().month(),
                               task_date_selection->selectedDate().year());
    if(due_date.is_void()) {
        invalid_date_error->showMessage(QString::fromStdString("date is invalid, cannot add task"));
        return;
    }

    task_name->clear();
    task_description->clear();

    client->add_composite(name, description, due_date);
    sync_with_model();
}

void ListView::on_delete_clicked() {
    if(task_display_table->selectedItems().size()) {
        client->remove_child(task_display_table->selectedItems()[0]->row());
        sync_with_model();
    }
    else {
        std::cerr<<"no items selected, cannot delete"<<std::endl;
    }
}

void ListView::on_edit_name_clicked() {
    if(!any_selections()) {
        nothing_selected_error->showMessage("no task selected, cannot edit description");
        return;
    }
    int row = selected_row();
    std::string new_text = task_name->text().toStdString();
    client->get_child(row)->set_name(new_text);
    task_name->clear();
        
    sync_with_model();
}

void ListView::on_edit_description_clicked() {
    if(!any_selections()) {
        nothing_selected_error->showMessage("no task selected, cannot edit description");
        return;
    }
    int row = selected_row();
    std::string new_text = task_description->text().toStdString();
    client->get_child(row)->set_description(new_text);
    task_name->clear();
        
    sync_with_model();
}

void ListView::on_edit_date_clicked() {
    if(!any_selections()) {
        nothing_selected_error->showMessage("no task selected, cannot edit date");
        return;
    }
    int row = selected_row();
    std::string new_text = task_description->text().toStdString();
    Date selected = Date::from((int)task_date_selection->selectedDate().day(),
                               (int)task_date_selection->selectedDate().month(),
                               (int)task_date_selection->selectedDate().year());

    client->get_child(row)->set_date(selected);
    task_name->clear();
        
    sync_with_model();
}

// move around the tree
void ListView::on_move_to_clicked() {
    if(!any_selections()) {
        nothing_selected_error->showMessage("no task selected, cannot move to");
        return;
    }
    int row = selected_row();
    if(std::dynamic_pointer_cast<TaskComposite>(client->curr_children_list()[row])) {
       client->go_to_child(row);
    }
    else
        cannot_go_to_leaf_error->showMessage("cannot move to leaf node");
    sync_with_model();
}

void ListView::on_move_up_clicked() {
    client->go_up();
    sync_with_model();
}

void ListView::on_mark_done_clicked() {
    if(!any_selections()) {
        nothing_selected_error->showMessage("no task selected, cannot move to");
        return;
    }
    auto task = client->curr_children_list()[selected_row()];
    TaskDoableChecker tdc;
    if(tdc.is_doable(task.get())) {
        task->mark_done();
        sync_with_model();
    }
    else {
        cannot_mark_done_error->showMessage("task cannot be completed, unfinished subtasks");
    }
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
