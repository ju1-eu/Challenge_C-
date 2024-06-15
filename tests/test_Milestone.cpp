#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Milestone.h"

TEST_CASE("Milestone creation and search") {
    Milestone milestone1(1, "Milestone 1", "Description 1");
    Milestone milestone2(2, "Milestone 2", "Description 2");
    std::vector<Milestone> milestones = { milestone1, milestone2 };

    REQUIRE(Milestone::searchMilestones(milestones, "Milestone 1").size() == 1);
    REQUIRE(Milestone::searchMilestones(milestones, "Milestone 3").size() == 0);
}

TEST_CASE("Milestone editing and task management") {
    Milestone milestone(1, "Milestone 1", "Description 1");
    milestone.editMilestone("New Milestone 1", "New Description 1");
    REQUIRE(milestone.getTitle() == "New Milestone 1");
    REQUIRE(milestone.getDescription() == "New Description 1");

    Task task1(1, "Task 1", "Description 1");
    Task task2(2, "Task 2", "Description 2");
    milestone.addTask(task1);
    milestone.addTask(task2);
    REQUIRE(milestone.tasks.size() == 2);

    milestone.removeTask(1);
    REQUIRE(milestone.tasks.size() == 1);
}
