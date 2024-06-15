#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <ctime>
#include <fstream>

enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

class Task {
private:
    int id;
    std::string title;
    std::string description;
    bool completed;
    std::time_t dueDate;
    Priority priority;

public:
    Task(int id = 0, const std::string& title = "", const std::string& description = "");

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    bool isCompleted() const;
    std::time_t getDueDate() const;
    Priority getPriority() const;

    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);
    void setCompleted(bool isCompleted);
    void setDueDate(const std::time_t& newDueDate);
    void setPriority(Priority newPriority);

    void editTask(const std::string& newTitle, const std::string& newDescription);
    static std::vector<Task> searchTasks(const std::vector<Task>& taskList, const std::string& searchTerm);

    // Methoden zur Speicherung und zum Laden
    void save(std::ofstream& outFile) const;
    static Task load(std::ifstream& inFile);
};

#endif // TASK_H
