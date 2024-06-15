#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string title;
    std::string description;
    bool completed;

public:
    Task(int id, const std::string& title, const std::string& description);

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    bool isCompleted() const;
    void setCompleted(bool completed);
};

#endif // TASK_H
