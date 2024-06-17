#include "CLI.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>

// Task-related functions
void CLI::addTask(std::vector<Task>& tasks, int id, const std::string& title, const std::string& description) {
    tasks.emplace_back(id, title, description);
}

void CLI::removeTask(std::vector<Task>& tasks, int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.getId() == id;
    }), tasks.end());
}

void CLI::displayTasks(const std::vector<Task>& tasks, std::ostream& out) {
    out << "\n========== Aufgabenliste ==========\n";
    for (const auto& task : tasks) {
        out << "------------------------------------\n";
        out << "ID: " << task.getId() << "\n";
        out << "Titel: " << task.getTitle() << "\n";
        out << "Beschreibung: " << task.getDescription() << "\n";
        out << "Erledigt: " << (task.isCompleted() ? "Ja" : "Nein") << "\n";

        // Fälligkeitsdatum anzeigen
        std::time_t dueDate = task.getDueDate();
        if (dueDate != 0) {
            out << "Fälligkeitsdatum: " << std::put_time(std::localtime(&dueDate), "%Y-%m-%d") << "\n";
        } else {
            out << "Fälligkeitsdatum: Nicht gesetzt\n";
        }

        // Priorität anzeigen
        out << "Priorität: ";
        switch (task.getPriority()) {
            case Priority::LOW:
                out << "LOW";
                break;
            case Priority::MEDIUM:
                out << "MEDIUM";
                break;
            case Priority::HIGH:
                out << "HIGH";
                break;
        }
        out << "\n------------------------------------\n";
    }
    out << "====================================\n";
}

void CLI::editTask(std::vector<Task>& tasks, int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        std::string choice;
        std::cout << "Möchten Sie den Titel ändern? (ja/nein): ";
        std::getline(std::cin, choice);
        if (choice == "ja") {
            std::string newTitle;
            std::cout << "Neuer Titel: ";
            std::getline(std::cin, newTitle);
            it->setTitle(newTitle);
        }

        std::cout << "Möchten Sie die Beschreibung ändern? (ja/nein): ";
        std::getline(std::cin, choice);
        if (choice == "ja") {
            std::string newDescription;
            std::cout << "Neue Beschreibung: ";
            std::getline(std::cin, newDescription);
            it->setDescription(newDescription);
        }

        std::cout << "Möchten Sie den Erledigt-Status ändern? (ja/nein): ";
        std::getline(std::cin, choice);
        if (choice == "ja") {
            std::string completed;
            std::cout << "Erledigt (ja/nein): ";
            std::getline(std::cin, completed);
            it->setCompleted(completed == "ja");
        }

        std::cout << "Möchten Sie das Fälligkeitsdatum ändern? (ja/nein): ";
        std::getline(std::cin, choice);
        if (choice == "ja") {
            std::string dueDateStr;
            std::cout << "Fälligkeitsdatum (YYYY-MM-DD): ";
            std::getline(std::cin, dueDateStr);
            std::tm tm = {};
            std::istringstream ss(dueDateStr);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            std::time_t dueDate = std::mktime(&tm);
            it->setDueDate(dueDate);
        }

        std::cout << "Möchten Sie die Priorität ändern? (ja/nein): ";
        std::getline(std::cin, choice);
        if (choice == "ja") {
            int priority;
            std::cout << "Priorität (0: LOW, 1: MEDIUM, 2: HIGH): ";
            std::cin >> priority;
            std::cin.ignore(); // Ignore newline character after integer input
            it->setPriority(static_cast<Priority>(priority));
        }
    } else {
        std::cout << "Aufgabe nicht gefunden.\n";
    }
}

// Milestone-related functions
void CLI::addMilestone(std::vector<Milestone>& milestones, int id, const std::string& title, const std::string& description) {
    milestones.emplace_back(id, title, description);
}

void CLI::removeMilestone(std::vector<Milestone>& milestones, int id) {
    milestones.erase(std::remove_if(milestones.begin(), milestones.end(), [id](const Milestone& milestone) {
        return milestone.getId() == id;
    }), milestones.end());
}

void CLI::displayMilestones(const std::vector<Milestone>& milestones, std::ostream& out) {
    out << "\n========== Meilensteinliste ==========\n";
    for (const auto& milestone : milestones) {
        out << "--------------------------------------\n";
        out << "ID: " << milestone.getId() << "\n";
        out << "Titel: " << milestone.getTitle() << "\n";
        out << "Beschreibung: " << milestone.getDescription() << "\n";
        out << "Tasks:\n";
        for (const auto& task : milestone.getTasks()) {
            out << "  - " << task.getId() << ": " << task.getTitle() << ": " << task.getDescription() << "\n";
        }
        if (milestone.getTasks().empty()) {
            out << "  Keine Aufgaben zugewiesen\n";
        }
        out << "--------------------------------------\n";
    }
    out << "======================================\n";
}

void CLI::editMilestone(std::vector<Milestone>& milestones, int id, const std::string& newTitle, const std::string& newDescription) {
    for (auto& milestone : milestones) {
        if (milestone.getId() == id) {
            milestone.setTitle(newTitle);
            milestone.setDescription(newDescription);
            break;
        }
    }
}

void CLI::addTaskToMilestone(std::vector<Milestone>& milestones, const Task& task, int milestoneId) {
    for (auto& milestone : milestones) {
        if (milestone.getId() == milestoneId) {
            milestone.addTask(task);
            break;
        }
    }
}

std::vector<Task> CLI::searchTasks(const std::vector<Task>& tasks, const std::string& searchTerm) {
    std::vector<Task> results;
    for (const auto& task : tasks) {
        if (task.getTitle().find(searchTerm) != std::string::npos || task.getDescription().find(searchTerm) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}

std::vector<Milestone> CLI::searchMilestones(const std::vector<Milestone>& milestones, const std::string& searchTerm) {
    std::vector<Milestone> results;
    for (const auto& milestone : milestones) {
        if (milestone.getTitle().find(searchTerm) != std::string::npos || milestone.getDescription().find(searchTerm) != std::string::npos) {
            results.push_back(milestone);
        }
    }
    return results;
}

void CLI::setTaskDueDate(std::vector<Task>& tasks, int id, std::time_t dueDate) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setDueDate(dueDate);
            break;
        }
    }
}

void CLI::setTaskPriority(std::vector<Task>& tasks, int id, Priority priority) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setPriority(priority);
            break;
        }
    }
}

// Save and Load functions
void CLI::saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::trunc); // Datei im Truncate-Modus öffnen
    if (outFile.is_open()) {
        outFile << "TASKS\n";
        for (const auto& task : tasks) {
            outFile << task.getId() << '\n';
            outFile << "Titel: " << task.getTitle() << '\n';
            outFile << "Beschreibung: " << task.getDescription() << '\n';
            outFile << "Erledigt: " << (task.isCompleted() ? "Ja" : "Nein") << '\n';
            std::time_t dueDate = task.getDueDate();
            if (dueDate != 0) {
                outFile << "Fälligkeitsdatum: " << std::put_time(std::localtime(&dueDate), "%Y-%m-%d") << '\n';
            } else {
                outFile << "Fälligkeitsdatum: Nicht gesetzt\n";
            }
            outFile << "Priorität: ";
            switch (task.getPriority()) {
                case Priority::LOW:
                    outFile << "LOW";
                    break;
                case Priority::MEDIUM:
                    outFile << "MEDIUM";
                    break;
                case Priority::HIGH:
                    outFile << "HIGH";
                    break;
            }
            outFile << '\n';
        }
        outFile.close(); // Datei schließen
    } else {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
    }
}


void CLI::loadTasks(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        std::getline(inFile, line); // Überspringen Sie die Kopfzeile "TASKS"
        while (std::getline(inFile, line)) {
            if (line.empty()) continue;

            int id = std::stoi(line);
            std::string title, description, completedStr, dueDateStr, priorityStr;
            std::getline(inFile, title);
            std::getline(inFile, description);
            std::getline(inFile, completedStr);
            std::getline(inFile, dueDateStr);
            std::getline(inFile, priorityStr);

            title = title.substr(title.find(": ") + 2);
            description = description.substr(description.find(": ") + 2);
            completedStr = completedStr.substr(completedStr.find(": ") + 2);
            dueDateStr = dueDateStr.substr(dueDateStr.find(": ") + 2);
            priorityStr = priorityStr.substr(priorityStr.find(": ") + 2);

            bool completed = (completedStr == "Ja");
            std::time_t dueDate = 0;
            if (dueDateStr != "Nicht gesetzt") {
                std::tm tm = {};
                std::istringstream ss(dueDateStr);
                ss >> std::get_time(&tm, "%Y-%m-%d");
                dueDate = std::mktime(&tm);
            }
            Priority priority = (priorityStr == "LOW") ? Priority::LOW :
                               (priorityStr == "MEDIUM") ? Priority::MEDIUM :
                                                           Priority::HIGH;

            Task task(id, title, description);
            task.setCompleted(completed);
            task.setDueDate(dueDate);
            task.setPriority(priority);
            tasks.push_back(task);
        }
        inFile.close(); // Datei schließen
    } else {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
    }
}

void CLI::saveMilestones(const std::vector<Milestone>& milestones, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::trunc); // Datei im Truncate-Modus öffnen
    if (outFile.is_open()) {
        outFile << "MILESTONES\n";
        for (const auto& milestone : milestones) {
            outFile << milestone.getId() << '\n';
            outFile << "Titel: " << milestone.getTitle() << '\n';
            outFile << "Beschreibung: " << milestone.getDescription() << '\n';
            outFile << "Tasks:\n";
            for (const auto& task : milestone.getTasks()) {
                outFile << "  - " << task.getId() << ": " << task.getTitle() << ": " << task.getDescription() << '\n';
            }
            outFile << '\n';
        }
        outFile.close(); // Datei schließen
    } else {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
    }
}

void CLI::loadMilestones(std::vector<Milestone>& milestones, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        std::getline(inFile, line); // Überspringen Sie die Kopfzeile "MILESTONES"
        while (std::getline(inFile, line)) {
            if (line.empty()) continue;

            int id = std::stoi(line);
            std::string title, description, tasksStr;
            std::getline(inFile, title);
            std::getline(inFile, description);

            title = title.substr(title.find(": ") + 2);
            description = description.substr(description.find(": ") + 2);

            Milestone milestone(id, title, description);

            if (std::getline(inFile, tasksStr) && tasksStr.find("Tasks:") == 0) {
                while (std::getline(inFile, tasksStr) && tasksStr.find("  - ") == 0) {
                    int taskId = std::stoi(tasksStr.substr(4, tasksStr.find(":") - 4));
                    std::string taskTitle = tasksStr.substr(tasksStr.find(": ") + 2, tasksStr.rfind(":") - (tasksStr.find(": ") + 2));
                    std::string taskDescription = tasksStr.substr(tasksStr.rfind(": ") + 2);
                    milestone.addTask(Task(taskId, taskTitle, taskDescription));
                }
            }

            milestones.push_back(milestone);
        }
        inFile.close(); // Datei schließen
    } else {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename << std::endl;
    }
}

void CLI::batchAddTasks(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Fehler beim Öffnen der Datei: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(inFile, line); // Überspringen Sie die Kopfzeile "TASKS"
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        int id = std::stoi(line);
        std::string title, description, completedStr, dueDateStr, priorityStr;
        std::getline(inFile, title);
        std::getline(inFile, description);
        std::getline(inFile, completedStr);
        std::getline(inFile, dueDateStr);
        std::getline(inFile, priorityStr);

        title = title.substr(title.find(": ") + 2);
        description = description.substr(description.find(": ") + 2);
        completedStr = completedStr.substr(completedStr.find(": ") + 2);
        dueDateStr = dueDateStr.substr(dueDateStr.find(": ") + 2);
        priorityStr = priorityStr.substr(priorityStr.find(": ") + 2);

        bool completed = (completedStr == "Ja");
        std::time_t dueDate = 0;
        if (dueDateStr != "Nicht gesetzt") {
            std::tm tm = {};
            std::istringstream ss(dueDateStr);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            dueDate = std::mktime(&tm);
        }
        Priority priority = (priorityStr == "LOW") ? Priority::LOW :
                           (priorityStr == "MEDIUM") ? Priority::MEDIUM :
                                                       Priority::HIGH;

        Task task(id, title, description);
        task.setCompleted(completed);
        task.setDueDate(dueDate);
        task.setPriority(priority);
        tasks.push_back(task);
    }
    inFile.close(); // Datei schließen
}

void CLI::batchAddMilestones(std::vector<Milestone>& milestones, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Fehler beim Öffnen der Datei: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(inFile, line); // Überspringen Sie die Kopfzeile "MILESTONES"
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        int id = std::stoi(line);
        std::string title, description, tasksStr;
        std::getline(inFile, title);
        std::getline(inFile, description);

        title = title.substr(title.find(": ") + 2);
        description = description.substr(description.find(": ") + 2);

        Milestone milestone(id, title, description);

        if (std::getline(inFile, tasksStr) && tasksStr.find("Tasks:") == 0) {
            while (std::getline(inFile, tasksStr) && tasksStr.find("  - ") == 0) {
                int taskId = std::stoi(tasksStr.substr(4, tasksStr.find(":") - 4));
                std::string taskTitle = tasksStr.substr(tasksStr.find(": ") + 2, tasksStr.rfind(":") - (tasksStr.find(": ") + 2));
                std::string taskDescription = tasksStr.substr(tasksStr.rfind(": ") + 2);
                milestone.addTask(Task(taskId, taskTitle, taskDescription));
            }
        }

        milestones.push_back(milestone);
    }
    inFile.close(); // Datei schließen
}
