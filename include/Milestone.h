#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
#include <vector>
#include "Task.h"

class Milestone {
public:
    Milestone(int id, const std::string& title, const std::string& description);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;

    void addTask(const Task& task);
    void removeTask(int taskId);
    void editMilestone(const std::string& newTitle, const std::string& newDescription);
    std::vector<Task> getTasks() const;
    void displayMilestone() const;

    // Neue Methoden für setTitle und setDescription
    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);

    // Deklaration der searchMilestones Methode
    static std::vector<Milestone> searchMilestones(const std::vector<Milestone>& milestoneList, const std::string& searchTerm);

private:
    int id;
    std::string title;
    std::string description;
    std::vector<Task> tasks;
};

#endif // MILESTONE_H
