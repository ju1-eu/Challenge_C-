#ifndef MILESTONE_H
#define MILESTONE_H

#include <string>
#include <vector>
#include "Task.h"
#include <fstream>

class Milestone {
public:
    Milestone(int id = 0, const std::string& title = "", const std::string& description = "");

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;

    void addTask(const Task& task);
    void removeTask(int taskId);
    void editMilestone(const std::string& newTitle, const std::string& newDescription);
    std::vector<Task> getTasks() const;
    void displayMilestone() const;

    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);

    static std::vector<Milestone> searchMilestones(const std::vector<Milestone>& milestoneList, const std::string& searchTerm);

    // Methoden zur Speicherung und zum Laden
    void save(std::ofstream& outFile) const;
    static Milestone load(std::ifstream& inFile);

private:
    int id;
    std::string title;
    std::string description;
    std::vector<Task> tasks;
};

#endif // MILESTONE_H
