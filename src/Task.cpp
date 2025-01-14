#include "Task.h"

Task::Task(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description), completed(false), dueDate(0), priority(Priority::LOW) {}

int Task::getId() const {
    return id;
}

const std::string& Task::getTitle() const {
    return title;
}

const std::string& Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

std::time_t Task::getDueDate() const {
    return dueDate;
}

Priority Task::getPriority() const {
    return priority;
}

void Task::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Task::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Task::setCompleted(bool isCompleted) {
    completed = isCompleted;
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
        if (task.getTitle().find(searchTerm) != std::string::npos || task.getDescription().find(searchTerm) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}

void Task::save(std::ofstream& outFile) const {
    outFile << id << '\n'
            << title << '\n'
            << description << '\n'
            << completed << '\n'
            << dueDate << '\n'
            << static_cast<int>(priority) << '\n';
}

Task Task::load(std::ifstream& inFile) {
    int id;
    std::string title;
    std::string description;
    bool completed;
    std::time_t dueDate;
    int priorityInt;

    inFile >> id;
    inFile.ignore();
    std::getline(inFile, title);
    std::getline(inFile, description);
    inFile >> completed;
    inFile >> dueDate;
    inFile >> priorityInt;

    Task task(id, title, description);
    task.setCompleted(completed);
    task.setDueDate(dueDate);
    task.setPriority(static_cast<Priority>(priorityInt));

    return task;
}
