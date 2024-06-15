#include "catch.hpp"
#include "Task.h"

// Testfall für die Erstellung einer Aufgabe
TEST_CASE("Task creation", "[task]") {
    Task task(1, "Test Aufgabe", "Testen der Aufgabenerstellung");

    REQUIRE(task.getId() == 1);
    REQUIRE(task.getTitle() == "Test Aufgabe");
    REQUIRE(task.getDescription() == "Testen der Aufgabenerstellung");
    REQUIRE(task.isCompleted() == false);

    task.setCompleted(true);
    REQUIRE(task.isCompleted() == true);
}
