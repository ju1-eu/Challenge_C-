#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Task.h"

TEST_CASE("Task Erstellung und Getter", "[Task]") {
    Task task(1, "Aufgabe 1", "Beschreibung für Aufgabe 1");

    REQUIRE(task.getId() == 1);
    REQUIRE(task.getTitle() == "Aufgabe 1");
    REQUIRE(task.getDescription() == "Beschreibung für Aufgabe 1");
    REQUIRE(task.isCompleted() == false);
}

TEST_CASE("Task Setter", "[Task]") {
    Task task(1, "Aufgabe 1", "Beschreibung für Aufgabe 1");

    task.setTitle("Neue Aufgabe 1");
    task.setDescription("Neue Beschreibung für Aufgabe 1");
    task.setCompleted(true);

    REQUIRE(task.getTitle() == "Neue Aufgabe 1");
    REQUIRE(task.getDescription() == "Neue Beschreibung für Aufgabe 1");
    REQUIRE(task.isCompleted() == true);
}
