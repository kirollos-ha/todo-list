#include <QApplication>
#include <fstream>

#include "include/view/View.hpp"
#include "include/ui/TaskClient.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::ifstream ifs("task.save", std::ifstream::in);
    TaskClient tc = TaskClient(ifs);
    std::cout<<std::endl;

    ListView v(&tc);
    v.show();

    return app.exec();
}
