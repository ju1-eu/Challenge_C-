#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Task.h"
#include "Milestone.h"
#include "CLI.h"
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

TEST_CASE("Aufgabenverwaltung", "[tasks]") {
    std::vector<Task> tasks;

    SECTION("Aufgabe hinzufügen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        REQUIRE(tasks.size() == 1);
        REQUIRE(tasks[0].getTitle() == "Aufgabe 1");
    }

    SECTION("Aufgabe entfernen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        removeTask(tasks, 1);
        REQUIRE(tasks.empty());
    }

    SECTION("Aufgaben anzeigen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        std::ostringstream oss;
        displayTasks(tasks, oss);
        REQUIRE(oss.str().find("Aufgabe 1") != std::string::npos);
    }

    SECTION("Aufgabe bearbeiten") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        editTask(tasks, 1, "Aufgabe 1 bearbeitet", "Beschreibung 1 bearbeitet");
        REQUIRE(tasks[0].getTitle() == "Aufgabe 1 bearbeitet");
        REQUIRE(tasks[0].getDescription() == "Beschreibung 1 bearbeitet");
    }

    SECTION("Fälligkeitsdatum setzen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        std::tm dueDate = {};
        std::istringstream ss("2023-12-31");
        ss >> std::get_time(&dueDate, "%Y-%m-%d");
        setTaskDueDate(tasks, 1, mktime(&dueDate));
        REQUIRE(tasks[0].getDueDate() == mktime(&dueDate));
    }

    SECTION("Priorität setzen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        setTaskPriority(tasks, 1, Priority::HIGH);
        REQUIRE(tasks[0].getPriority() == Priority::HIGH);
    }

    SECTION("Aufgaben suchen") {
        addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        auto results = searchTasks(tasks, "Aufgabe 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Aufgabe 1");
    }
}

TEST_CASE("Meilensteinverwaltung", "[milestones]") {
    std::vector<Milestone> milestones;

    SECTION("Meilenstein hinzufügen") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        REQUIRE(milestones.size() == 1);
        REQUIRE(milestones[0].getTitle() == "Meilenstein 1");
    }

    SECTION("Meilenstein entfernen") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        removeMilestone(milestones, 1);
        REQUIRE(milestones.empty());
    }

    SECTION("Meilensteine anzeigen") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        std::ostringstream oss;
        displayMilestones(milestones, oss);
        REQUIRE(oss.str().find("Meilenstein 1") != std::string::npos);
    }

    SECTION("Meilenstein bearbeiten") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        editMilestone(milestones, 1, "Meilenstein 1 bearbeitet", "Beschreibung 1 bearbeitet");
        REQUIRE(milestones[0].getTitle() == "Meilenstein 1 bearbeitet");
        REQUIRE(milestones[0].getDescription() == "Beschreibung 1 bearbeitet");
    }

    SECTION("Meilensteine suchen") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        auto results = searchMilestones(milestones, "Meilenstein 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Meilenstein 1");
    }

    SECTION("Aufgabe zu Meilenstein hinzufügen") {
        addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        Task task(1, "Aufgabe 1", "Beschreibung 1");
        addTaskToMilestone(milestones, task, 1);
        REQUIRE(milestones[0].getTasks().size() == 1);
        REQUIRE(milestones[0].getTasks()[0].getTitle() == "Aufgabe 1");
    }
}
