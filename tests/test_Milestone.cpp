#include "catch.hpp"
#include "Milestone.h"
#include <fstream>

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
        REQUIRE(milestone.getTasks()[0].getId() == 2);
    }

    SECTION("Editing milestone") {
        milestone.editMilestone("New Milestone 1", "New Description 1");
        REQUIRE(milestone.getTitle() == "New Milestone 1");
        REQUIRE(milestone.getDescription() == "New Description 1");
    }

    SECTION("Searching milestones") {
        milestone.editMilestone("New Milestone 1", "New Description 1"); // Ensure milestone is edited
        std::vector<Milestone> milestones = {milestone};
        std::vector<Milestone> results = Milestone::searchMilestones(milestones, "New Milestone 1");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "New Milestone 1");
    }

    SECTION("Displaying milestone") {
        milestone.displayMilestone();
        // Check console output manually
    }

    SECTION("Saving and loading a milestone") {
        std::ofstream outFile("milestone_test.txt");
        milestone.save(outFile);
        outFile.close();

        std::ifstream inFile("milestone_test.txt");
        Milestone loadedMilestone = Milestone::load(inFile);
        inFile.close();

        REQUIRE(loadedMilestone.getId() == milestone.getId());
        REQUIRE(loadedMilestone.getTitle() == milestone.getTitle());
        REQUIRE(loadedMilestone.getDescription() == milestone.getDescription());
        REQUIRE(loadedMilestone.getTasks().size() == milestone.getTasks().size());
        REQUIRE(loadedMilestone.getTasks()[0].getId() == milestone.getTasks()[0].getId());
        REQUIRE(loadedMilestone.getTasks()[0].getTitle() == milestone.getTasks()[0].getTitle());
        REQUIRE(loadedMilestone.getTasks()[0].getDescription() == milestone.getTasks()[0].getDescription());
    }
}
