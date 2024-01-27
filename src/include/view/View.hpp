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

#include "../ui/TaskClient.hpp"

class ListView : public QMainWindow
{
    Q_OBJECT

public:
    ListView(TaskClient* tc, QWidget *parent = nullptr);
    ~ListView();

private:
    QPushButton* add_leaf_button;
    QPushButton* add_composite_button;
    QPushButton* delete_button;
    QPushButton* edit_button;

    QPushButton* move_to_button;
    QPushButton* move_up_button;

    QPushButton* quit_button;
    QPushButton* save_and_quit_button;
    

    QLineEdit* line;
    QTableWidget* table;

    TaskClient* client;
    // init
    void create_widgets();
    void configure_widgets();
    void lay_widgets_out();
    void connect_slots();
    
    // update methods
    void sync_with_model();

private slots:
    // update slots
    void on_add_leaf_clicked();
    void on_add_composite_clicked();
    void on_delete_clicked();
    void on_edit_clicked();

    void on_move_to_clicked();
    void on_move_up_clicked();

    void on_quit_clicked();
    void on_save_and_quit_clicked();
};

#endif // TODO_GUI_H
