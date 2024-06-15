#include "catch.hpp"
#include "Task.h"
#include "Milestone.h"
#include "CLI.h"
#include <vector>
#include <sstream>
#include <iomanip>

TEST_CASE("CLI functionalities", "[CLI]") {
    std::vector<Task> tasks;
    std::vector<Milestone> milestones;

    SECTION("Add a task") {
        addTask(tasks, 1, "Task 1", "Description 1");
        REQUIRE(tasks.size() == 1);
        REQUIRE(tasks[0].getTitle() == "Task 1");
    }

    SECTION("Remove a task") {
        addTask(tasks, 1, "Task 1", "Description 1");
        removeTask(tasks, 1);
        REQUIRE(tasks.size() == 0);
    }

    SECTION("Display tasks") {
        addTask(tasks, 1, "Task 1", "Description 1");
        std::ostringstream oss;
        displayTasks(tasks, oss);
        REQUIRE(oss.str().find("Task 1") != std::string::npos);
    }

    SECTION("Edit a task") {
        addTask(tasks, 1, "Task 1", "Description 1");
        editTask(tasks, 1, "Task 1 Edited", "Description 1 Edited");
        REQUIRE(tasks[0].getTitle() == "Task 1 Edited");
        REQUIRE(tasks[0].getDescription() == "Description 1 Edited");
    }

    SECTION("Add a milestone") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        REQUIRE(milestones.size() == 1);
        REQUIRE(milestones[0].getTitle() == "Milestone 1");
    }

    SECTION("Remove a milestone") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        removeMilestone(milestones, 1);
        REQUIRE(milestones.size() == 0);
    }

    SECTION("Display milestones") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        std::ostringstream oss;
        displayMilestones(milestones, oss);
        REQUIRE(oss.str().find("Milestone 1") != std::string::npos);
    }

    SECTION("Edit a milestone") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        editMilestone(milestones, 1, "Milestone 1 Edited", "Description 1 Edited");
        REQUIRE(milestones[0].getTitle() == "Milestone 1 Edited");
        REQUIRE(milestones[0].getDescription() == "Description 1 Edited");
    }

    SECTION("Add task to milestone") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        addTask(tasks, 1, "Task 1", "Description 1");
        addTaskToMilestone(milestones, tasks[0], 1);
        REQUIRE(milestones[0].getTasks().size() == 1);
        REQUIRE(milestones[0].getTasks()[0].getTitle() == "Task 1");
    }

    SECTION("Search tasks") {
        addTask(tasks, 1, "Task 1", "Description 1");
        auto results = searchTasks(tasks, "Task 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Task 1");
    }

    SECTION("Search milestones") {
        addMilestone(milestones, 1, "Milestone 1", "Description 1");
        auto results = searchMilestones(milestones, "Milestone 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Milestone 1");
    }

    SECTION("Set task due date") {
        addTask(tasks, 1, "Task 1", "Description 1");
        std::tm dueDate = {};
        std::istringstream ss("2023-12-31");
        ss >> std::get_time(&dueDate, "%Y-%m-%d");
        setTaskDueDate(tasks, 1, mktime(&dueDate));
        REQUIRE(tasks[0].getDueDate() == mktime(&dueDate));
    }

    SECTION("Set task priority") {
        addTask(tasks, 1, "Task 1", "Description 1");
        setTaskPriority(tasks, 1, Priority::HIGH);
        REQUIRE(tasks[0].getPriority() == Priority::HIGH);
    }
}
