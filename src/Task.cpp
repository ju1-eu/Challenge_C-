#include "Task.h"

Task::Task(int id, const std::string &title, const std::string &description) 
    : id(id), title(title), description(description), completed(false) {}

int Task::getId() const {
    return id;
}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setTitle(const std::string &title) {
    this->title = title;
}

void Task::setDescription(const std::string &description) {
    this->description = description;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}
