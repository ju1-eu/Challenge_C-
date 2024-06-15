#include <iostream>
#include <vector>
#include "Task.h"
#include "Milestone.h"

// Funktion zum Hinzufügen einer Aufgabe
void addTask(std::vector<Task>& tasks, int id, const std::string& title, const std::string& description) {
    Task newTask(id, title, description);
    tasks.push_back(newTask);
}

// Funktion zum Entfernen einer Aufgabe
void removeTask(std::vector<Task>& tasks, int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [id](const Task& task) { return task.getId() == id; }),
                tasks.end());
}

// Funktion zum Anzeigen aller Aufgaben
void displayTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        std::cout << "Aufgaben-ID: " << task.getId() << std::endl;
        std::cout << "Titel: " << task.getTitle() << std::endl;
        std::cout << "Beschreibung: " << task.getDescription() << std::endl;
        std::cout << "Erledigt: " << (task.isCompleted() ? "Ja" : "Nein") << std::endl;
        std::cout << std::endl;
    }
}

// Funktion zum Hinzufügen eines Meilensteins
void addMilestone(std::vector<Milestone>& milestones, int id, const std::string& title, const std::string& description) {
    Milestone newMilestone(id, title, description);
    milestones.push_back(newMilestone);
}

// Funktion zum Entfernen eines Meilensteins
void removeMilestone(std::vector<Milestone>& milestones, int id) {
    milestones.erase(std::remove_if(milestones.begin(), milestones.end(),
                                    [id](const Milestone& milestone) { return milestone.getId() == id; }),
                     milestones.end());
}

// Funktion zum Anzeigen aller Meilensteine
void displayMilestones(const std::vector<Milestone>& milestones) {
    for (const auto& milestone : milestones) {
        milestone.displayMilestone();
    }
}

int main() {
    std::vector<Task> tasks;
    std::vector<Milestone> milestones;

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

    // Beispiel zum Hinzufügen von Meilensteinen
    addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung für Meilenstein 1");
    addMilestone(milestones, 2, "Meilenstein 2", "Beschreibung für Meilenstein 2");

    // Beispiel zum Hinzufügen von Aufgaben zu Meilensteinen
    milestones[0].addTask(Task(3, "Aufgabe 3", "Beschreibung für Aufgabe 3"));

    // Beispiel zum Anzeigen von Meilensteinen
    std::cout << "Anzeigen der Meilensteine:" << std::endl;
    displayMilestones(milestones);

    // Beispiel zum Entfernen eines Meilensteins
    removeMilestone(milestones, 1);

    // Anzeigen der Meilensteine nach dem Entfernen
    std::cout << "Anzeigen der Meilensteine nach dem Entfernen:" << std::endl;
    displayMilestones(milestones);

    return 0;
}
