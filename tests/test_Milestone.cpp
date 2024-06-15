#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Milestone.h"

TEST_CASE("Milestone functionalities", "[Milestone]") {
    Milestone milestone(1, "Milestone 1", "Description 1");

    Task task1(1, "Task 1", "Task 1 Description");
    Task task2(2, "Task 2", "Task 2 Description");

    milestone.addTask(task1);
    milestone.addTask(task2);

    SECTION("Adding tasks") {
        REQUIRE(milestone.getTasks().size() == 2);
    }

    SECTION("Removing tasks") {
        milestone.removeTask(1);
        REQUIRE(milestone.getTasks().size() == 1);
    }

    SECTION("Editing milestone") {
        milestone.editMilestone("New Milestone 1", "New Description 1");
        REQUIRE(milestone.getTitle() == "New Milestone 1");
        REQUIRE(milestone.getDescription() == "New Description 1");
    }

    SECTION("Searching milestones") {
        std::vector<Milestone> milestones = {milestone};
        std::vector<Milestone> results = Milestone::searchMilestones(milestones, "Milestone 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "New Milestone 1");
    }

    SECTION("Displaying milestone") {
        milestone.displayMilestone();
        // Check console output manually
    }
}
