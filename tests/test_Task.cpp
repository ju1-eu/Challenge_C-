#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Task.h"

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
}
