#include "CLI.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
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
    std::cout << "12. Beenden\n";
    std::cout << "Wählen Sie eine Option: ";
}

int main() {
    std::vector<Task> tasks;
    std::vector<Milestone> milestones;

    CLI cli;
    cli.loadTasks(tasks, "tasks.txt");
    cli.loadMilestones(milestones, "milestones.txt");

    int option;
    do {
        printMainMenu();
        std::cin >> option;
        std::cin.ignore(); // Ignorieren Sie das nachfolgende Newline-Zeichen

        switch (option) {
            case 1: {
                int id;
                std::string title, description;
                std::cout << "Aufgaben-ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Titel: ";
                std::getline(std::cin, title);
                std::cout << "Beschreibung: ";
                std::getline(std::cin, description);
                cli.addTask(tasks, id, title, description);
                break;
            }
            case 2: {
                int id;
                std::cout << "Aufgaben-ID zum Entfernen: ";
                std::cin >> id;
                cli.removeTask(tasks, id);
                break;
            }
            case 3: {
                cli.displayTasks(tasks, std::cout);
                break;
            }
            case 4: {
                int id;
                std::cout << "Aufgaben-ID zum Bearbeiten: ";
                std::cin >> id;
                std::cin.ignore();
                cli.editTask(tasks, id);
                break;
            }
            case 5: {
                int id;
                std::string title, description;
                std::cout << "Meilenstein-ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Titel: ";
                std::getline(std::cin, title);
                std::cout << "Beschreibung: ";
                std::getline(std::cin, description);
                cli.addMilestone(milestones, id, title, description);
                break;
            }
            case 6: {
                int id;
                std::cout << "Meilenstein-ID zum Entfernen: ";
                std::cin >> id;
                cli.removeMilestone(milestones, id);
                break;
            }
            case 7: {
                cli.displayMilestones(milestones, std::cout);
                break;
            }
            case 8: {
                int id;
                std::string newTitle, newDescription;
                std::cout << "Meilenstein-ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Neuer Titel: ";
                std::getline(std::cin, newTitle);
                std::cout << "Neue Beschreibung: ";
                std::getline(std::cin, newDescription);
                cli.editMilestone(milestones, id, newTitle, newDescription);
                break;
            }
            case 9: {
                int milestoneId, taskId;
                std::cout << "Meilenstein-ID: ";
                std::cin >> milestoneId;
                std::cout << "Aufgaben-ID: ";
                std::cin >> taskId;
                std::cin.ignore();
                auto it = std::find_if(tasks.begin(), tasks.end(), [taskId](const Task& task) { return task.getId() == taskId; });
                if (it != tasks.end()) {
                    cli.addTaskToMilestone(milestones, *it, milestoneId);
                } else {
                    std::cout << "Aufgabe nicht gefunden.\n";
                }
                break;
            }
            case 10: {
                std::string searchTerm;
                std::cout << "Suchbegriff: ";
                std::cin.ignore();
                std::getline(std::cin, searchTerm);
                auto results = cli.searchTasks(tasks, searchTerm);
                cli.displayTasks(results, std::cout);
                break;
            }
            case 11: {
                std::string searchTerm;
                std::cout << "Suchbegriff: ";
                std::cin.ignore();
                std::getline(std::cin, searchTerm);
                auto results = cli.searchMilestones(milestones, searchTerm);
                cli.displayMilestones(results, std::cout);
                break;
            }
            case 12:
                std::cout << "Programm beendet.\n";
                break;
            default:
                std::cout << "Ungültige Option. Bitte erneut versuchen.\n";
                break;
        }
    } while (option != 12);

    cli.saveTasks(tasks, "tasks.txt");
    cli.saveMilestones(milestones, "milestones.txt");

    return 0;
}
