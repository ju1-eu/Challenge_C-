#include "catch.hpp"
#include "CLI.h"
#include "Task.h"
#include "Milestone.h"
#include <sstream>

TEST_CASE("Test adding and displaying tasks") {
    CLI cli;
    std::vector<Task> tasks;
    std::ostringstream oss;

    cli.addTask(tasks, 1, "Test Task", "This is a test task.");
    cli.displayTasks(tasks, oss);

    std::string output = oss.str();
    REQUIRE(output.find("ID: 1") != std::string::npos);
    REQUIRE(output.find("Titel: Test Task") != std::string::npos);
    REQUIRE(output.find("Beschreibung: This is a test task.") != std::string::npos);
}

TEST_CASE("Test removing tasks") {
    CLI cli;
    std::vector<Task> tasks;

    cli.addTask(tasks, 1, "Test Task", "This is a test task.");
    cli.removeTask(tasks, 1);

    REQUIRE(tasks.size() == 0);
}

TEST_CASE("Test editing tasks") {
    CLI cli;
    std::vector<Task> tasks;
    std::ostringstream oss;

    cli.addTask(tasks, 1, "Test Task", "This is a test task.");
    tasks[0].setTitle("Edited Task");
    tasks[0].setDescription("This is an edited task.");
    tasks[0].setCompleted(true);

    cli.displayTasks(tasks, oss);

    std::string output = oss.str();
    REQUIRE(output.find("Titel: Edited Task") != std::string::npos);
    REQUIRE(output.find("Beschreibung: This is an edited task.") != std::string::npos);
    REQUIRE(output.find("Erledigt: Ja") != std::string::npos);
}

TEST_CASE("Test searching tasks") {
    CLI cli;
    std::vector<Task> tasks;
    cli.addTask(tasks, 1, "Test Task", "This is a test task.");
    cli.addTask(tasks, 2, "Another Task", "This is another test task.");

    auto results = cli.searchTasks(tasks, "Another");

    REQUIRE(results.size() == 1);
    REQUIRE(results[0].getTitle() == "Another Task");
}

TEST_CASE("Test displaying milestones") {
    CLI cli;
    std::vector<Milestone> milestones;
    std::ostringstream oss;

    cli.addMilestone(milestones, 1, "Test Milestone", "This is a test milestone.");
    cli.displayMilestones(milestones, oss);

    std::string output = oss.str();
    REQUIRE(output.find("ID: 1") != std::string::npos);
    REQUIRE(output.find("Titel: Test Milestone") != std::string::npos);
    REQUIRE(output.find("Beschreibung: This is a test milestone.") != std::string::npos);
}

TEST_CASE("Test removing milestones") {
    CLI cli;
    std::vector<Milestone> milestones;

    cli.addMilestone(milestones, 1, "Test Milestone", "This is a test milestone.");
    cli.removeMilestone(milestones, 1);

    REQUIRE(milestones.size() == 0);
}

TEST_CASE("Test searching milestones") {
    CLI cli;
    std::vector<Milestone> milestones;
    cli.addMilestone(milestones, 1, "Test Milestone", "This is a test milestone.");
    cli.addMilestone(milestones, 2, "Another Milestone", "This is another test milestone.");

    auto results = cli.searchMilestones(milestones, "Another");

    REQUIRE(results.size() == 1);
    REQUIRE(results[0].getTitle() == "Another Milestone");
}
