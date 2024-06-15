#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>
#include <ctime>
#include "Task.h"
#include "Milestone.h"

void addTask(std::vector<Task>& tasks, int id, const std::string& title, const std::string& description);
void removeTask(std::vector<Task>& tasks, int id);
void displayTasks(const std::vector<Task>& tasks, std::ostream& out);
void editTask(std::vector<Task>& tasks, int id, const std::string& newTitle, const std::string& newDescription);

void addMilestone(std::vector<Milestone>& milestones, int id, const std::string& title, const std::string& description);
void removeMilestone(std::vector<Milestone>& milestones, int id);
void displayMilestones(const std::vector<Milestone>& milestones, std::ostream& out);
void editMilestone(std::vector<Milestone>& milestones, int id, const std::string& newTitle, const std::string& newDescription);

void addTaskToMilestone(std::vector<Milestone>& milestones, const Task& task, int milestoneId);
std::vector<Task> searchTasks(const std::vector<Task>& tasks, const std::string& searchTerm);
std::vector<Milestone> searchMilestones(const std::vector<Milestone>& milestones, const std::string& searchTerm);

void setTaskDueDate(std::vector<Task>& tasks, int id, std::time_t dueDate);
void setTaskPriority(std::vector<Task>& tasks, int id, Priority priority);

#endif // CLI_H
