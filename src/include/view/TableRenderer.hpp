#ifndef TABLE_RENDERER_H
#define TABLE_RENDERER_H

#include<QTableWidget>
#include <sstream>

#include "../task/TaskComponent.hpp"
#include "../task/TaskComposite.hpp"
#include "../task/TaskLeaf.hpp"
#include "../ui/TaskClient.hpp"
#include "../task/initializers.hpp"


class TableRenderer : public TaskVisitor {
public:
    void render_model(TaskClient* client, QTableWidget* table) {
        index = 0;
        this->table = table;
        int n = client-> curr_n_children();
        table->setRowCount(n);
        table->setColumnCount(3);

        for(int i = 0; i<n; ++i) {
            auto comp = client->get_child(i);
            comp->accept(this);
        }
    }

    void current_task_to_table(const TaskComponent* comp) const {
        std::string name = comp->get_name();
        std::string desc = comp->get_description();
        std::stringstream render_date;
        render_date << comp->get_date().get_day() << " / "
                    << comp->get_date().get_month() << " / "
                    << comp->get_date().get_year();
        std::string date_s = render_date.str();

        table->setItem(index, 0,
                       new QTableWidgetItem(QString::fromStdString(name)));
        table->setItem(index, 1,
                       new QTableWidgetItem(QString::fromStdString(date_s)));
        table->setItem(index, 2,
                       new QTableWidgetItem(QString::fromStdString(desc)));
        // grey out if done
        if(comp->is_done()) {
            for(int i = 0; i<3; ++i)
                table->item(index, i)->setForeground
                    (QBrush(QColor(128, 128, 128)));
        }
        // reddish background if overdue
        if(comp->is_overdue()) {
            for(int i = 0; i<3; ++i)
                table->item(index, i)->setBackground
                    (QBrush(QColor(200, 160, 160)));
        }
        // normal (white) background if not overdue
        else {
            for(int i = 0; i<3; ++i)
                table->item(index, i)->setBackground
                    (QBrush(QColor(255, 255, 255)));
        }
    }

    virtual void visitLeaf(TaskLeaf* l) override {
        current_task_to_table(l);
        advance();
    }
    virtual void visitComposite(TaskComposite* c) override {
        current_task_to_table(c);
        QFont boldFont;
        boldFont.setBold(true);
        table->item(index, 0)->setFont(boldFont);
        advance();
    }
private:
    QTableWidget* table;
    int index;
    void advance() {
        index++;
    }
};

#endif
