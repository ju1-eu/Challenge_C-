#include "Milestone.h"
#include <iostream>
#include <algorithm>

Milestone::Milestone(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description) {}

int Milestone::getId() const {
    return id;
}

const std::string& Milestone::getTitle() const {
    return title;
}

const std::string& Milestone::getDescription() const {
    return description;
}

void Milestone::addTask(const Task& task) {
    tasks.push_back(task);
}

void Milestone::removeTask(int taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [taskId](const Task& task) {
        return task.getId() == taskId;
    }), tasks.end());
}

void Milestone::editMilestone(const std::string& newTitle, const std::string& newDescription) {
    title = newTitle;
    description = newDescription;
}

std::vector<Task> Milestone::getTasks() const {
    return tasks;
}

void Milestone::displayMilestone() const {
    std::cout << "Milestone ID: " << id << ", Title: " << title << ", Description: " << description << std::endl;
    std::cout << "Tasks:" << std::endl;
    for (const auto& task : tasks) {
        std::cout << "  - " << task.getTitle() << ": " << task.getDescription() << std::endl;
    }
}

void Milestone::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Milestone::setDescription(const std::string& newDescription) {
    description = newDescription;
}

std::vector<Milestone> Milestone::searchMilestones(const std::vector<Milestone>& milestoneList, const std::string& searchTerm) {
    std::vector<Milestone> results;
    std::copy_if(milestoneList.begin(), milestoneList.end(), std::back_inserter(results),
                 [&searchTerm](const Milestone& milestone) {
                     return milestone.getTitle().find(searchTerm) != std::string::npos ||
                            milestone.getDescription().find(searchTerm) != std::string::npos;
                 });
    return results;
}

void Milestone::save(std::ofstream& outFile) const {
    outFile << id << '\n'
            << title << '\n'
            << description << '\n'
            << tasks.size() << '\n';
    for (const auto& task : tasks) {
        task.save(outFile);
    }
}

Milestone Milestone::load(std::ifstream& inFile) {
    int id;
    std::string title;
    std::string description;
    size_t taskCount;

    inFile >> id;
    inFile.ignore();
    std::getline(inFile, title);
    std::getline(inFile, description);
    inFile >> taskCount;
    inFile.ignore();

    Milestone milestone(id, title, description);
    for (size_t i = 0; i < taskCount; ++i) {
        Task task = Task::load(inFile);
        milestone.addTask(task);
    }

    return milestone;
}
