#include "Task.h"

Task::Task(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description), completed(false), dueDate(0), priority(LOW) {}

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

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

std::time_t Task::getDueDate() const {
    return dueDate;
}

Priority Task::getPriority() const {
    return priority;
}

void Task::setDueDate(const std::time_t& date) {
    dueDate = date;
}

void Task::setPriority(Priority newPriority) {
    priority = newPriority;
}

void Task::editTask(const std::string& newTitle, const std::string& newDescription) {
    title = newTitle;
    description = newDescription;
}

std::vector<Task> Task::searchTasks(const std::vector<Task>& taskList, const std::string& searchTerm) {
    std::vector<Task> results;
    for (const auto& task : taskList) {
        if (task.title.find(searchTerm) != std::string::npos || task.description.find(searchTerm) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}
