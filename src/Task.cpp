#include "Task.h"
#include <iostream>

// Konstruktor der Task-Klasse
Task::Task(const std::string& name, const std::string& description, const std::string& dueDate)
    : name(name), description(description), dueDate(dueDate) {}

// Getter-Methoden
std::string Task::getName() const {
    return name;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getDueDate() const {
    return dueDate;
}

// Setter-Methoden
void Task::setName(const std::string& name) {
    this->name = name;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setDueDate(const std::string& dueDate) {
    this->dueDate = dueDate;
}

// Methode zum Drucken der Aufgabe
void Task::printTask() const {
    std::cout << "Aufgabenname: " << name << "\nBeschreibung: " << description << "\nFälligkeitsdatum: " << dueDate << std::endl;
}