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
    CLI cli;

    SECTION("Aufgabe hinzufügen") {
        cli.addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        REQUIRE(tasks.size() == 1);
        REQUIRE(tasks[0].getTitle() == "Aufgabe 1");
    }

    SECTION("Aufgabe entfernen") {
        cli.addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        cli.removeTask(tasks, 1);
        REQUIRE(tasks.empty());
    }

    SECTION("Aufgaben anzeigen") {
        cli.addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        std::ostringstream oss;
        cli.displayTasks(tasks, oss);
        REQUIRE(oss.str().find("Aufgabe 1") != std::string::npos);
    }

    SECTION("Aufgabe bearbeiten") {
        cli.addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        tasks[0].setTitle("Bearbeitete Aufgabe");
        tasks[0].setDescription("Bearbeitete Beschreibung");
        tasks[0].setCompleted(true);
        REQUIRE(tasks[0].getTitle() == "Bearbeitete Aufgabe");
        REQUIRE(tasks[0].getDescription() == "Bearbeitete Beschreibung");
        REQUIRE(tasks[0].isCompleted() == true);
    }

    SECTION("Aufgaben suchen") {
        cli.addTask(tasks, 1, "Aufgabe 1", "Beschreibung 1");
        auto results = cli.searchTasks(tasks, "Aufgabe 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Aufgabe 1");
    }
}

TEST_CASE("Meilensteinverwaltung", "[milestones]") {
    std::vector<Milestone> milestones;
    CLI cli;

    SECTION("Meilenstein hinzufügen") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        REQUIRE(milestones.size() == 1);
        REQUIRE(milestones[0].getTitle() == "Meilenstein 1");
    }

    SECTION("Meilenstein entfernen") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        cli.removeMilestone(milestones, 1);
        REQUIRE(milestones.empty());
    }

    SECTION("Meilensteine anzeigen") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        std::ostringstream oss;
        cli.displayMilestones(milestones, oss);
        REQUIRE(oss.str().find("Meilenstein 1") != std::string::npos);
    }

    SECTION("Meilenstein bearbeiten") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        cli.editMilestone(milestones, 1, "Bearbeiteter Meilenstein", "Bearbeitete Beschreibung");
        REQUIRE(milestones[0].getTitle() == "Bearbeiteter Meilenstein");
        REQUIRE(milestones[0].getDescription() == "Bearbeitete Beschreibung");
    }

    SECTION("Meilensteine suchen") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        auto results = cli.searchMilestones(milestones, "Meilenstein 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Meilenstein 1");
    }

    SECTION("Aufgabe zu Meilenstein hinzufügen") {
        cli.addMilestone(milestones, 1, "Meilenstein 1", "Beschreibung 1");
        Task task(1, "Aufgabe 1", "Beschreibung 1");
        cli.addTaskToMilestone(milestones, task, 1);
        REQUIRE(milestones[0].getTasks().size() == 1);
        REQUIRE(milestones[0].getTasks()[0].getTitle() == "Aufgabe 1");
    }
}
