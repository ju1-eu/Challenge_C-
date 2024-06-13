#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    // Konstruktor der Task-Klasse
    Task(const std::string& name, const std::string& description, const std::string& dueDate);

    // Getter-Methoden
    std::string getName() const;
    std::string getDescription() const;
    std::string getDueDate() const;

    // Setter-Methoden
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setDueDate(const std::string& dueDate);

    // Methode zum Drucken der Aufgabe
    void printTask() const;

private:
    std::string name;          // Name der Aufgabe
    std::string description;   // Beschreibung der Aufgabe
    std::string dueDate;       // Fälligkeitsdatum der Aufgabe
};

#endif // TASK_H