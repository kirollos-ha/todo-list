#include <QApplication>
#include <istream>
#include <fstream>

#include "include/view/View.hpp"
#include "include/ui/TaskClient.hpp"
#include "include/task/initializers.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::ifstream task_file("task.save", std::ifstream::in);
    TaskClient tc(task_file);
    ListView v(&tc);
    v.show();

    return app.exec();
}
