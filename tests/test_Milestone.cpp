#include "catch.hpp"
#include "Milestone.h"
#include "Task.h"
#include <sstream>
#include <iostream>

// Testfall für die Meilenstein-Operationen
TEST_CASE("Meilenstein Operationen", "[milestone]") {
    Milestone milestone(1, "Test Meilenstein", "Testen der Meilensteinoperationen");

    REQUIRE(milestone.getId() == 1);
    REQUIRE(milestone.getTitle() == "Test Meilenstein");
    REQUIRE(milestone.getDescription() == "Testen der Meilensteinoperationen");

    Task task(1, "Test Aufgabe", "Testen der Aufgabenoperationen");
    milestone.addTask(task);

    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
    milestone.displayTasks();
    std::cout.rdbuf(old);

    REQUIRE(buffer.str() == "Aufgaben-ID: 1, Titel: Test Aufgabe, Beschreibung: Testen der Aufgabenoperationen\n");
}
