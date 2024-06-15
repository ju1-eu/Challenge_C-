#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
#include <vector>
#include "Task.h"

// Klasse zur Darstellung eines Meilensteins
class Milestone {
private:
    int id;
    std::string title;
    std::string description;
    std::vector<Task> tasks;

public:
    Milestone(int id, const std::string& title, const std::string& description);
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    void addTask(const Task& task);
    void removeTask(int taskId);
    void displayTasks() const;
    void displayMilestone() const;
};

#endif // MILESTONE_H
