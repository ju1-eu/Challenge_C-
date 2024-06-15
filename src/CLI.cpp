#include "CLI.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

// Task-related functions
void addTask(std::vector<Task>& tasks, int id, const std::string& title, const std::string& description) {
    tasks.emplace_back(id, title, description);
}

void removeTask(std::vector<Task>& tasks, int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.getId() == id;
    }), tasks.end());
}

void displayTasks(const std::vector<Task>& tasks, std::ostream& out) {
    for (const auto& task : tasks) {
        out << "ID: " << task.getId() << ", Title: " << task.getTitle() << ", Description: " << task.getDescription() << std::endl;
    }
}

void editTask(std::vector<Task>& tasks, int id, const std::string& newTitle, const std::string& newDescription) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setTitle(newTitle);
            task.setDescription(newDescription);
            break;
        }
    }
}

// Milestone-related functions
void addMilestone(std::vector<Milestone>& milestones, int id, const std::string& title, const std::string& description) {
    milestones.emplace_back(id, title, description);
}

void removeMilestone(std::vector<Milestone>& milestones, int id) {
    milestones.erase(std::remove_if(milestones.begin(), milestones.end(), [id](const Milestone& milestone) {
        return milestone.getId() == id;
    }), milestones.end());
}

void displayMilestones(const std::vector<Milestone>& milestones, std::ostream& out) {
    for (const auto& milestone : milestones) {
        out << "ID: " << milestone.getId() << ", Title: " << milestone.getTitle() << ", Description: " << milestone.getDescription() << std::endl;
    }
}

void editMilestone(std::vector<Milestone>& milestones, int id, const std::string& newTitle, const std::string& newDescription) {
    for (auto& milestone : milestones) {
        if (milestone.getId() == id) {
            milestone.setTitle(newTitle);
            milestone.setDescription(newDescription);
            break;
        }
    }
}

void addTaskToMilestone(std::vector<Milestone>& milestones, const Task& task, int milestoneId) {
    for (auto& milestone : milestones) {
        if (milestone.getId() == milestoneId) {
            milestone.addTask(task);
            break;
        }
    }
}

std::vector<Task> searchTasks(const std::vector<Task>& tasks, const std::string& searchTerm) {
    std::vector<Task> results;
    for (const auto& task : tasks) {
        if (task.getTitle().find(searchTerm) != std::string::npos || task.getDescription().find(searchTerm) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}

std::vector<Milestone> searchMilestones(const std::vector<Milestone>& milestones, const std::string& searchTerm) {
    std::vector<Milestone> results;
    for (const auto& milestone : milestones) {
        if (milestone.getTitle().find(searchTerm) != std::string::npos || milestone.getDescription().find(searchTerm) != std::string::npos) {
            results.push_back(milestone);
        }
    }
    return results;
}

void setTaskDueDate(std::vector<Task>& tasks, int id, std::time_t dueDate) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setDueDate(dueDate);
            break;
        }
    }
}

void setTaskPriority(std::vector<Task>& tasks, int id, Priority priority) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setPriority(priority);
            break;
        }
    }
}
