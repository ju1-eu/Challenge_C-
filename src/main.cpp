#include <iostream>
#include <vector>
#include "Task.h"

void addTask(std::vector<Task>& tasks, int id, const std::string& title, const std::string& description) {
    Task newTask(id, title, description);
    tasks.push_back(newTask);
}

void removeTask(std::vector<Task>& tasks, int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            break;
        }
    }
}

void displayTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        std::cout << "Aufgaben-ID: " << task.getId() << std::endl;
        std::cout << "Titel: " << task.getTitle() << std::endl;
        std::cout << "Beschreibung: " << task.getDescription() << std::endl;
        std::cout << "Erledigt: " << (task.isCompleted() ? "Ja" : "Nein") << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    
    // Beispiel zum Hinzufügen von Aufgaben
    addTask(tasks, 1, "Aufgabe 1", "Beschreibung für Aufgabe 1");
    addTask(tasks, 2, "Aufgabe 2", "Beschreibung für Aufgabe 2");

    // Beispiel zum Anzeigen von Aufgaben
    std::cout << "Anzeigen der Aufgaben:" << std::endl;
    displayTasks(tasks);

    // Beispiel zum Entfernen einer Aufgabe
    removeTask(tasks, 1);
    
    // Anzeigen der Aufgaben nach dem Entfernen
    std::cout << "Anzeigen der Aufgaben nach dem Entfernen:" << std::endl;
    displayTasks(tasks);

    return 0;
}
