#ifndef TASK_FILE_PARSER_H
#define TASK_FILE_PARSER_H

#include <stack>
#include <istream>
#include <memory>

#include "../task/TaskComposite.hpp"

class TaskFileParser {
public:
    TaskFileParser(){}
    std::shared_ptr<TaskComposite> read(std::istream&);

private:
    std::stack<std::shared_ptr<TaskComposite>> trace;

    void composite_start(std::istream&);
    void composite_end();
    void add_leaf(std::istream&);

    Date parse_date_string(const std::string& s);
};


#endif
