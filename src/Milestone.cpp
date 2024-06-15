#include "Milestone.h"
#include <iostream>

Milestone::Milestone(int id, const std::string& t, const std::string& d)
    : id(id), title(t), description(d) {}

int Milestone::getId() const {
    return id;
}

std::string Milestone::getTitle() const {
    return title;
}

std::string Milestone::getDescription() const {
    return description;
}

void Milestone::addTask(const Task& task) {
    tasks.push_back(task);
}

void Milestone::removeTask(int taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [&](const Task& task) { return task.getId() == taskId; }), tasks.end());
}

void Milestone::editMilestone(const std::string& newTitle, const std::string& newDescription) {
    title = newTitle;
    description = newDescription;
}

std::vector<Milestone> Milestone::searchMilestones(const std::vector<Milestone>& milestoneList, const std::string& searchTerm) {
    std::vector<Milestone> results;
    for (const auto& milestone : milestoneList) {
        if (milestone.title.find(searchTerm) != std::string::npos || milestone.description.find(searchTerm) != std::string::npos) {
            results.push_back(milestone);
        }
    }
    return results;
}

void Milestone::displayMilestone() const {
    std::cout << "Milestone ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Tasks: " << std::endl;
    for (const auto& task : tasks) {
        std::cout << "  - " << task.getTitle() << ": " << task.getDescription() << std::endl;
    }
}
