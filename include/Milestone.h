#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
#include <vector>
#include <algorithm>
#include "Task.h"

class Milestone {
private:
    int id;
    std::string title;
    std::string description;

public:
    std::vector<Task> tasks;

    Milestone(int id, const std::string& t, const std::string& d);

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;

    void addTask(const Task& task);
    void removeTask(int taskId);
    void editMilestone(const std::string& newTitle, const std::string& newDescription);
    void displayMilestone() const;

    static std::vector<Milestone> searchMilestones(const std::vector<Milestone>& milestoneList, const std::string& searchTerm);
};

#endif // MILESTONE_H
