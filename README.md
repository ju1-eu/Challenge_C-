# Challenge_Cpp

C++ Challenge: "Projektmanagementsystem"

### Ziel
Entwickle ein kleines Projektmanagementsystem in C++, das Aufgaben und Meilensteine verwaltet. Dieses Projekt wird dir helfen, wichtige Programmier- und Projektmanagementfähigkeiten zu erlernen und zu vertiefen.


```bash
project-management-system/
├── Makefile
├── README.md
├── build/
│   ├── Milestone.o
│   ├── Task.o
│   ├── main.o
│   ├── test_Milestone.o
│   ├── test_Task.o
├── include/
│   ├── Milestone.h
│   ├── Task.h
│   ├── catch.hpp
├── src/
│   ├── Milestone.cpp
│   ├── Task.cpp
│   ├── main.cpp
├── tests/
│   ├── test_Milestone.cpp
│   ├── test_Task.cpp
├── project_management_system
├── run_tests
```

## Kompilieren und Ausführen

```bash
# Terminal
make clean
make
# Tests ausführen:
make test

# Debugge die Tests in VSCode:
# Ausführen und debuggen Shift+Command+D
```

## Git

```bash
.gitignore Datei erstellen oder aktualisieren
echo "build/" > .gitignore
echo "project_management_system" >> .gitignore
echo "run_tests" >> .gitignore
echo ".vscode/" >> .gitignore

# Unnötige ausführbare Dateien entfernen
rm project_management_system run_tests

# Änderungen zum Commit vormerken
git add .

# Änderungen committen
git commit -m "Woche 3: Aufgabenverwaltung implementiert, Unit-Tests für Task-Klasse hinzugefügt"

# Änderungen pushen
git push origin main
```
