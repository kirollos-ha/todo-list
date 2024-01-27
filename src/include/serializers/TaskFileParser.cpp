#include<iostream>
#include <memory>
#include<string>
#include <utility>

#include"TaskFileParser.hpp"
#include"../task/initializers.hpp"

std::pair<std::string,std::string> split(std::string& s, char c) {
    int i = 0;
    while(i<s.length() && s[i] != c) {
        ++i;
    } 
    if(i == s.length()) {
        return std::make_pair(s, "");
    }
    return std::make_pair(s.substr(0, i), s.substr(i+1));
}

std::shared_ptr<TaskComposite> TaskFileParser::read(std::istream& ifs) {
    auto base = make_composite("");
    trace.push(base);

    std::string line;
    int i = 0;
    while(std::getline(ifs, line)) {
        auto command = split(line, ' ');

        std::string op = command.first;
        if(op == "cs") { // composite start
            composite_start(command.second);
        }
        else if(op == "ce") { // composite end
            composite_end();
        }
        else if(op == "l") { // leaf
            add_leaf(command.second);
        }
    }
    return std::dynamic_pointer_cast<TaskComposite>(base->get_child(0));

}

void TaskFileParser::composite_start(std::string& name) {
    auto new_task = make_composite(name);
    trace.top()->add(new_task);
    trace.push(new_task);
}

void TaskFileParser::composite_end() {
    trace.pop();
}

void TaskFileParser::add_leaf(std::string& name) {
    trace.top()->add(make_leaf(name));
}
