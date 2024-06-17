#include "catch.hpp"
#include "Task.h"
#include <sstream>

TEST_CASE("Test task creation and getters") {
    Task task(1, "Test Task", "This is a test task.");

    REQUIRE(task.getId() == 1);
    REQUIRE(task.getTitle() == "Test Task");
    REQUIRE(task.getDescription() == "This is a test task.");
    REQUIRE(task.isCompleted() == false);
    REQUIRE(task.getDueDate() == 0);
    REQUIRE(task.getPriority() == Priority::LOW);
}

TEST_CASE("Test task setters") {
    Task task(1, "Test Task", "This is a test task.");

    task.setTitle("Edited Task");
    task.setDescription("This is an edited task.");
    task.setCompleted(true);

    REQUIRE(task.getTitle() == "Edited Task");
    REQUIRE(task.getDescription() == "This is an edited task.");
    REQUIRE(task.isCompleted() == true);
}

TEST_CASE("Test task due date") {
    Task task(1, "Test Task", "This is a test task.");
    std::time_t dueDate = std::time(nullptr);
    task.setDueDate(dueDate);

    REQUIRE(task.getDueDate() == dueDate);
}

TEST_CASE("Test task priority") {
    Task task(1, "Test Task", "This is a test task.");
    task.setPriority(Priority::HIGH);

    REQUIRE(task.getPriority() == Priority::HIGH);
}

TEST_CASE("Test task search") {
    Task task1(1, "Test Task", "This is a test task.");
    Task task2(2, "Another Task", "This is another test task.");
    std::vector<Task> tasks = { task1, task2 };

    auto results = Task::searchTasks(tasks, "Another");

    REQUIRE(results.size() == 1);
    REQUIRE(results[0].getTitle() == "Another Task");
}
