#ifndef TODO_GUI_H
#define TODO_GUI_H

#include <QMainWindow>

#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QString>
#include <QLabel>
#include <QCalendarWidget>
#include <QErrorMessage>

#include "../ui/TaskClient.hpp"

class ListView : public QMainWindow
{
    Q_OBJECT

public:
    ListView(TaskClient* tc, QWidget *parent=nullptr);
    ~ListView();

private:
    QPushButton* add_leaf_button;
    QPushButton* add_composite_button;

    QPushButton* delete_button;

    QPushButton* edit_name_button;
    QPushButton* edit_description_button;
    QPushButton* edit_date_button;

    QPushButton* mark_done_button;

    QPushButton* move_to_button;
    QPushButton* move_up_button;

    QPushButton* quit_button;
    QPushButton* save_and_quit_button;

    QLabel* task_count_label;
    
    QLineEdit* task_name;
    QLineEdit* task_description;
    QCalendarWidget* task_date_selection;
    QTableWidget* task_display_table;

    TaskClient* client;
    QErrorMessage* nothing_selected_error;
    QErrorMessage* invalid_date_error;
    QErrorMessage* cannot_mark_done_error;
    QErrorMessage* cannot_go_to_leaf_error;
    // init
    void create_widgets();
    void create_other();
    void configure_widgets();
    void configure_other();
    void lay_widgets_out();
    void connect_slots();
    
    // update methods
    void sync_with_model();

    bool any_selections();
    int selected_row();

private slots:
    // update slots
    void on_add_leaf_clicked();
    void on_add_composite_clicked();
    
    void on_delete_clicked();

    void on_edit_name_clicked();
    void on_edit_description_clicked();
    void on_edit_date_clicked();

    void on_move_to_clicked();
    void on_move_up_clicked();

    void on_mark_done_clicked();

    void on_quit_clicked();
    void on_save_and_quit_clicked();
};

#endif // TODO_GUI_H
