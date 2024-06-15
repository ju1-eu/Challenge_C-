#include "catch.hpp"
#include "Task.h"
#include <fstream>
#include <ctime>
#include <vector>

TEST_CASE("Task functionalities", "[Task]") {
    Task task(1, "Task 1", "Description 1");

    SECTION("Setting and getting title") {
        task.setTitle("New Task 1");
        REQUIRE(task.getTitle() == "New Task 1");
    }

    SECTION("Setting and getting description") {
        task.setDescription("New Description 1");
        REQUIRE(task.getDescription() == "New Description 1");
    }

    SECTION("Setting and getting completion status") {
        task.setCompleted(true);
        REQUIRE(task.isCompleted() == true);
    }

    SECTION("Setting and getting due date") {
        std::time_t dueDate = std::time(nullptr);
        task.setDueDate(dueDate);
        REQUIRE(task.getDueDate() == dueDate);
    }

    SECTION("Setting and getting priority") {
        task.setPriority(Priority::MEDIUM);
        REQUIRE(task.getPriority() == Priority::MEDIUM);
    }

    SECTION("Saving and loading a task") {
        std::ofstream outFile("task_test.txt");
        task.save(outFile);
        outFile.close();

        std::ifstream inFile("task_test.txt");
        Task loadedTask = Task::load(inFile);
        inFile.close();

        REQUIRE(loadedTask.getId() == task.getId());
        REQUIRE(loadedTask.getTitle() == task.getTitle());
        REQUIRE(loadedTask.getDescription() == task.getDescription());
        REQUIRE(loadedTask.isCompleted() == task.isCompleted());
        REQUIRE(loadedTask.getDueDate() == task.getDueDate());
        REQUIRE(loadedTask.getPriority() == task.getPriority());
    }

    SECTION("Searching tasks") {
        std::vector<Task> tasks = {
            Task(1, "Task 1", "Description 1"),
            Task(2, "Task 2", "Description 2"),
            Task(3, "Special Task", "Special Description")
        };

        auto results = Task::searchTasks(tasks, "Special");
        REQUIRE(results.size() == 1);
        REQUIRE(results[0].getTitle() == "Special Task");
    }
}
