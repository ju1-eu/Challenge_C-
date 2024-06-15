#include <iostream>
#include <vector>
#include <ctime>
#include "Task.h"
#include "Milestone.h"

void printMainMenu() {
    std::cout << "\nProject Management System\n";
    std::cout << "1. Aufgabe hinzufügen\n";
    std::cout << "2. Aufgabe entfernen\n";
    std::cout << "3. Aufgaben anzeigen\n";
    std::cout << "4. Aufgabe bearbeiten\n";
    std::cout << "5. Meilenstein hinzufügen\n";
    std::cout << "6. Meilenstein entfernen\n";
    std::cout << "7. Meilensteine anzeigen\n";
    std::cout << "8. Meilenstein bearbeiten\n";
    std::cout << "9. Aufgabe zu Meilenstein hinzufügen\n";
    std::cout << "10. Aufgabe suchen\n";
    std::cout << "11. Meilenstein suchen\n";
    std::cout << "12. Aufgabe Fälligkeitstermin setzen\n";
    std::cout << "13. Aufgabe Priorität setzen\n";
    std::cout << "14. Beenden\n";
    std::cout << "Wählen Sie eine Option: ";
}

void addTask(std::vector<Task>& tasks) {
    int id;
    std::string title, description;
    std::cout << "Aufgaben-ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Titel: ";
    std::getline(std::cin, title);
    std::cout << "Beschreibung: ";
    std::getline(std::cin, description);
    tasks.push_back(Task(id, title, description));
}

void removeTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "Aufgaben-ID zum Entfernen: ";
    std::cin >> id;
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [id](const Task& task) { return task.getId() == id; }),
                tasks.end());
}

void displayTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        std::cout << "Aufgaben-ID: " << task.getId() << std::endl;
        std::cout << "Titel: " << task.getTitle() << std::endl;
        std::cout << "Beschreibung: " << task.getDescription() << std::endl;
        std::cout << "Erledigt: " << (task.isCompleted() ? "Ja" : "Nein") << std::endl;
        std::time_t dueDate = task.getDueDate();
        std::cout << "Fälligkeitsdatum: " << std::ctime(&dueDate);
        std::cout << "Priorität: " << static_cast<int>(task.getPriority()) << std::endl;
        std::cout << std::endl;
    }
}

void editTask(std::vector<Task>& tasks) {
    int id;
    std::string newTitle, newDescription;
    std::cout << "Aufgaben-ID zum Bearbeiten: ";
    std::cin >> id;
    std::cin.ignore();
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        std::cout << "Neuer Titel: ";
        std::getline(std::cin, newTitle);
        std::cout << "Neue Beschreibung: ";
        std::getline(std::cin, newDescription);
        it->editTask(newTitle, newDescription);
    } else {
        std::cout << "Aufgabe nicht gefunden.\n";
    }
}

void setTaskDueDate(std::vector<Task>& tasks) {
    int id;
    std::cout << "Aufgaben-ID: ";
    std::cin >> id;
    std::cin.ignore();
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        std::time_t dueDate;
        std::cout << "Fälligkeitstermin (epoch time): ";
        std::cin >> dueDate;
        it->setDueDate(dueDate);
    } else {
        std::cout << "Aufgabe nicht gefunden.\n";
    }
}

void setTaskPriority(std::vector<Task>& tasks) {
    int id;
    int priority;
    std::cout << "Aufgaben-ID: ";
    std::cin >> id;
    std::cin.ignore();
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        std::cout << "Priorität (0: LOW, 1: MEDIUM, 2: HIGH): ";
        std::cin >> priority;
        it->setPriority(static_cast<Priority>(priority));
    } else {
        std::cout << "Aufgabe nicht gefunden.\n";
    }
}

void searchTasks(const std::vector<Task>& tasks) {
    std::string searchTerm;
    std::cout << "Suchbegriff: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);
    std::vector<Task> results = Task::searchTasks(tasks, searchTerm);
    displayTasks(results);
}

void addMilestone(std::vector<Milestone>& milestones) {
    int id;
    std::string title, description;
    std::cout << "Meilenstein-ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Titel: ";
    std::getline(std::cin, title);
    std::cout << "Beschreibung: ";
    std::getline(std::cin, description);
    milestones.push_back(Milestone(id, title, description));
}

void removeMilestone(std::vector<Milestone>& milestones) {
    int id;
    std::cout << "Meilenstein-ID zum Entfernen: ";
    std::cin >> id;
    milestones.erase(std::remove_if(milestones.begin(), milestones.end(),
                                    [id](const Milestone& milestone) { return milestone.getId() == id; }),
                     milestones.end());
}

void displayMilestones(const std::vector<Milestone>& milestones) {
    for (const auto& milestone : milestones) {
        milestone.displayMilestone();
    }
}

void editMilestone(std::vector<Milestone>& milestones) {
    int id;
    std::string newTitle, newDescription;
    std::cout << "Meilenstein-ID zum Bearbeiten: ";
    std::cin >> id;
    std::cin.ignore();
    auto it = std::find_if(milestones.begin(), milestones.end(), [id](const Milestone& milestone) { return milestone.getId() == id; });
    if (it != milestones.end()) {
        std::cout << "Neuer Titel: ";
        std::getline(std::cin, newTitle);
        std::cout << "Neue Beschreibung: ";
        std::getline(std::cin, newDescription);
        it->editMilestone(newTitle, newDescription);
    } else {
        std::cout << "Meilenstein nicht gefunden.\n";
    }
}

void searchMilestones(const std::vector<Milestone>& milestones) {
    std::string searchTerm;
    std::cout << "Suchbegriff: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);
    std::vector<Milestone> results = Milestone::searchMilestones(milestones, searchTerm);
    displayMilestones(results);
}

void addTaskToMilestone(std::vector<Milestone>& milestones) {
    int milestoneId, taskId;
    std::string title, description;
    std::cout << "Meilenstein-ID: ";
    std::cin >> milestoneId;
    auto it = std::find_if(milestones.begin(), milestones.end(), [milestoneId](const Milestone& milestone) { return milestone.getId() == milestoneId; });
    if (it != milestones.end()) {
        std::cout << "Aufgaben-ID: ";
        std::cin >> taskId;
        std::cin.ignore();
        std::cout << "Titel: ";
        std::getline(std::cin, title);
        std::cout << "Beschreibung: ";
        std::getline(std::cin, description);
        it->addTask(Task(taskId, title, description));
    } else {
        std::cout << "Meilenstein nicht gefunden.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    std::vector<Milestone> milestones;
    int option;
    do {
        printMainMenu();
        std::cin >> option;
        std::cin.ignore();
        switch (option) {
            case 1: addTask(tasks); break;
            case 2: removeTask(tasks); break;
            case 3: displayTasks(tasks); break;
            case 4: editTask(tasks); break;
            case 5: addMilestone(milestones); break;
            case 6: removeMilestone(milestones); break;
            case 7: displayMilestones(milestones); break;
            case 8: editMilestone(milestones); break;
            case 9: addTaskToMilestone(milestones); break;
            case 10: searchTasks(tasks); break;
            case 11: searchMilestones(milestones); break;
            case 12: setTaskDueDate(tasks); break;
            case 13: setTaskPriority(tasks); break;
            case 14: std::cout << "Programm beendet.\n"; break;
            default: std::cout << "Ungültige Option. Bitte erneut versuchen.\n"; break;
        }
    } while (option != 14);
    return 0;
}
