#include "catch.hpp"
#include "Milestone.h"
#include "Task.h"
#include <sstream>

TEST_CASE("Test adding tasks to milestones") {
    Milestone milestone(1, "Test Milestone", "This is a test milestone.");
    Task task(1, "Test Task", "This is a test task.");

    milestone.addTask(task);

    REQUIRE(milestone.getTasks().size() == 1);
    REQUIRE(milestone.getTasks()[0].getTitle() == "Test Task");
}

TEST_CASE("Test removing tasks from milestones") {
    Milestone milestone(1, "Test Milestone", "This is a test milestone.");
    Task task(1, "Test Task", "This is a test task.");

    milestone.addTask(task);
    milestone.removeTask(1);

    REQUIRE(milestone.getTasks().size() == 0);
}

TEST_CASE("Test editing milestones") {
    Milestone milestone(1, "Test Milestone", "This is a test milestone.");
    milestone.setTitle("Edited Milestone");
    milestone.setDescription("This is an edited milestone.");

    REQUIRE(milestone.getTitle() == "Edited Milestone");
    REQUIRE(milestone.getDescription() == "This is an edited milestone.");
}

TEST_CASE("Test displaying milestones") {
    Milestone milestone(1, "Test Milestone", "This is a test milestone.");
    std::ostringstream oss;
    milestone.displayMilestone();
    oss << "Milestone ID: " << milestone.getId() << ", Title: " << milestone.getTitle() << ", Description: " << milestone.getDescription() << std::endl;
    oss << "Tasks:" << std::endl;
    for (const auto& task : milestone.getTasks()) {
        oss << "  - " << task.getTitle() << ": " << task.getDescription() << std::endl;
    }

    std::string output = oss.str();
    REQUIRE(output.find("Milestone ID: 1") != std::string::npos);
    REQUIRE(output.find("Title: Test Milestone") != std::string::npos);
    REQUIRE(output.find("Description: This is a test milestone.") != std::string::npos);
}

TEST_CASE("Test searching milestones") {
    Milestone milestone1(1, "Test Milestone", "This is a test milestone.");
    Milestone milestone2(2, "Another Milestone", "This is another test milestone.");
    std::vector<Milestone> milestones = { milestone1, milestone2 };

    auto results = Milestone::searchMilestones(milestones, "Another");

    REQUIRE(results.size() == 1);
    REQUIRE(results[0].getTitle() == "Another Milestone");
}
