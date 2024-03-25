#include<iostream>
#include <memory>
#include<string>
#include <utility>

#include"TaskFileParser.hpp"
#include"../task/initializers.hpp"

std::shared_ptr<TaskComposite> TaskFileParser::read(std::istream& ifs) {
    std::string root_name="root", root_desc="root node";
    Date d = Date::from(1,1,1970);
    auto base = make_root_composite(root_name, root_desc, d);
    trace.push(base);

    std::string cmd;
    while(std::getline(ifs, cmd)) {
        if(cmd == "cs") { // composite start
            composite_start(ifs);
        }
        if(cmd == "ce") {
            composite_end();
        }
        else if(cmd == "l") { // leaf
            add_leaf(ifs);
        }
    }
    return std::dynamic_pointer_cast<TaskComposite>(base->get_child(0));
}

void TaskFileParser::composite_start(std::istream& ifs) {
    std::string name, date_str, description;
    std::getline(ifs, name);
    std::getline(ifs, date_str);
    std::getline(ifs, description);
    Date date = parse_date_string(date_str);

    auto comp = make_composite(name, description, date, trace.top());
    trace.push(comp);
}

void TaskFileParser::composite_end() {
    trace.pop();
}

void TaskFileParser::add_leaf(std::istream& ifs) {
    std::string name, date_str, description;
    std::getline(ifs, name);
    std::getline(ifs, date_str);
    std::getline(ifs, description);
    Date date = parse_date_string(date_str);

    make_leaf(name, description, date, trace.top());
}

Date TaskFileParser::parse_date_string(const std::string& s) {
    std::stringstream ss(s);
    int year, month, day;
    ss >> year >> month >> day;
    return Date::from(day, month, year);
}
