#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Task.h"

TEST_CASE("Task creation and search") {
    Task task1(1, "Task 1", "Description 1");
    Task task2(2, "Task 2", "Description 2");
    std::vector<Task> tasks = { task1, task2 };

    REQUIRE(Task::searchTasks(tasks, "Task 1").size() == 1);
    REQUIRE(Task::searchTasks(tasks, "Task 3").size() == 0);
}

TEST_CASE("Task editing and properties") {
    Task task(1, "Task 1", "Description 1");
    task.editTask("New Task 1", "New Description 1");
    REQUIRE(task.getTitle() == "New Task 1");
    REQUIRE(task.getDescription() == "New Description 1");

    std::time_t now = std::time(nullptr);
    task.setDueDate(now);
    REQUIRE(task.getDueDate() == now);

    task.setPriority(MEDIUM);
    REQUIRE(task.getPriority() == MEDIUM);
    
    task.setCompleted(true);
    REQUIRE(task.isCompleted() == true);
}
