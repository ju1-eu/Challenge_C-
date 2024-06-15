#include "Milestone.h"
#include <iostream>
#include <algorithm>

// Konstruktor für die Klasse Milestone
Milestone::Milestone(int id, const std::string& title, const std::string& description)
    : id(id), title(title), description(description) {}

// Getter für die ID
int Milestone::getId() const {
    return id;
}

// Getter für den Titel
std::string Milestone::getTitle() const {
    return title;
}

// Getter für die Beschreibung
std::string Milestone::getDescription() const {
    return description;
}

// Methode zum Hinzufügen einer Aufgabe
void Milestone::addTask(const Task& task) {
    tasks.push_back(task);
}

// Methode zum Entfernen einer Aufgabe
void Milestone::removeTask(int taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [taskId](const Task& task) { return task.getId() == taskId; }), tasks.end());
}

// Methode zum Anzeigen der Aufgaben
void Milestone::displayTasks() const {
    for (const auto& task : tasks) {
        std::cout << "Aufgaben-ID: " << task.getId() << ", Titel: " << task.getTitle() << ", Beschreibung: " << task.getDescription() << std::endl;
    }
}

// Methode zum Anzeigen des Meilensteins
void Milestone::displayMilestone() const {
    std::cout << "Meilenstein-ID: " << id << ", Titel: " << title << ", Beschreibung: " << description << std::endl;
    displayTasks();
}
