#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

enum Priority { LOW, MEDIUM, HIGH };

class Task {
private:
    int id;
    std::string title;
    std::string description;
    bool completed;
    std::time_t dueDate;
    Priority priority;

public:
    Task(int id, const std::string& title, const std::string& description);

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    bool isCompleted() const;
    void setCompleted(bool completed);

    std::time_t getDueDate() const;
    Priority getPriority() const;

    void setDueDate(const std::time_t& date);
    void setPriority(Priority newPriority);
    void editTask(const std::string& newTitle, const std::string& newDescription);

    static std::vector<Task> searchTasks(const std::vector<Task>& taskList, const std::string& searchTerm);
};

#endif // TASK_H
