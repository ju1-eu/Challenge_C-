#include "Task.h"

// Konstruktor für die Klasse Task
Task::Task(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description), completed(false) {}

// Getter für die ID
int Task::getId() const {
    return id;
}

// Getter für den Titel
std::string Task::getTitle() const {
    return title;
}

// Getter für die Beschreibung
std::string Task::getDescription() const {
    return description;
}

// Überprüft, ob die Aufgabe erledigt ist
bool Task::isCompleted() const {
    return completed;
}

// Setzt den Erledigt-Status der Aufgabe
void Task::setCompleted(bool completed) {
    this->completed = completed;
}
