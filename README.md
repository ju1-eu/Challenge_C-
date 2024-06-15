# C++ Challenge: "Projektmanagementsystem"

## Ziel

Entwickle ein kleines Projektmanagementsystem in C++, das Aufgaben und Meilensteine verwaltet. Dieses Projekt wird dir helfen, wichtige Programmier- und Projektmanagementfähigkeiten zu erlernen und zu vertiefen.

## Verzeichnisstruktur

```bash
project-management-system/
├── Makefile
├── README.md
├── build/
│   ├── CLI.o
│   ├── Milestone.o
│   ├── Task.o
│   ├── main.o
│   ├── test_CLI.o
│   ├── test_Milestone.o
│   ├── test_Task.o
│   ├── test_main.o
├── include/
│   ├── CLI.h
│   ├── Milestone.h
│   ├── Task.h
│   ├── catch.hpp
├── src/
│   ├── CLI.cpp
│   ├── Milestone.cpp
│   ├── Task.cpp
│   ├── main.cpp
├── tests/
│   ├── test_CLI.cpp
│   ├── test_Milestone.cpp
│   ├── test_Task.cpp
│   ├── test_main.cpp
├── project_management_system
├── run_tests
```

## Kompilieren und Ausführen

### Terminal

```bash
cd project-management-system
make clean
make
./project_management_system
make test
./run_tests
```

### VSCode-Editor

Ausführen und debuggen (Shift+Command+D)

## Git - Projekt-Verwaltung

### Aufräumen

```bash
# .gitignore Datei erstellen oder aktualisieren
echo "build/" > .gitignore
echo "project_management_system" >> .gitignore
echo "run_tests" >> .gitignore
echo ".vscode/" >> .gitignore

# Unnötige ausführbare Dateien entfernen
make clean
```

### Projekt Änderungen

```bash
# Änderungen zum Commit vormerken
git add .

# Änderungen committen
git commit -m "Tag 3: "

# Änderungen pushen
git push origin main

# Tag hinzufügen
git tag -a v1.0 -m "Tag 3: Meilensteine hinzufügen"

# Tag pushen
git push origin v1.0
```

### Commit-Nachrichten ändern

```bash
# Änderungen im Git-Commit-Verlauf vornehmen
# Schritt 1: Starte den interaktiven Rebase
git rebase -i HEAD~3
# Schritt 2: Ändere die Commit-Nachrichten
#   Ersetze pick durch reword (ändern)
# Schritt 3: Ändere die Commit-Nachrichten
git push --force
```

## Debuggen mit LLDB

1. **Programm kompilieren mit Debug-Informationen**:   
   Kompilieren Sie das Programm:
   ```sh
   make clean
   make
   ```

2. **Programm mit LLDB starten**:
   ```sh
   lldb ./project_management_system
   ```

3. **Ziel erstellen und Breakpoints setzen**:
   ```sh
   target create "./project_management_system"
   breakpoint set --name main
   ```

4. **Programm ausführen**:
   ```sh
   run
   ```

   Das Programm wird bis zum `main` Breakpoint ausgeführt und dort gestoppt.

5. **Schrittweise durch den Code gehen**:
   Verwenden Sie die folgenden Befehle, um das Programm zu durchlaufen:
   - **`next`** (`n`): Führt die nächste Zeile im aktuellen Funktionskontext aus.
   - **`step`** (`s`): Tritt in die nächste Zeile, auch wenn dies eine Funktion ist.
   - **`finish`**: Läuft bis zum Ende der aktuellen Funktion.
   - **`continue`** (`c`): Setzt die Programmausführung bis zum nächsten Breakpoint fort.
   
   Beispiel:
   ```sh
   next
   ```

6. **Variablen überprüfen**:
   Verwenden Sie den `print` Befehl, um den Wert von Variablen zu überprüfen.
   ```sh
   print tasks
   print milestones
   ```

7. **Quellcode anzeigen**:
   Um den aktuellen Quellcode anzuzeigen:
   ```sh
   source list
   ```

### Debugging-Tipps

- **Setzen Sie Breakpoints strategisch**: Setzen Sie Breakpoints an Stellen, an denen Sie den Programmfluss und die Variablen überprüfen möchten.
  ```sh
  breakpoint set --name addTask
  ```

- **Verwenden Sie `next` und `step` sinnvoll**: Verwenden Sie `next`, um die nächste Zeile auszuführen, und `step`, um in Funktionen einzutreten.
  ```sh
  next
  step
  ```

### Beispiel-Debugging-Sitzung

1. **Programm starten und bis zum `main` Breakpoint laufen lassen**:
   ```sh
   lldb ./project_management_system
   target create "./project_management_system"
   breakpoint set --name main
   run
   ```

2. **Schrittweise durch den Code gehen und Variablen überprüfen**:
   ```sh
   next
   print tasks
   next
   print milestones
   step
   print newTask
   finish
   print tasks
   ```

3. **Untersuchung und Analyse**:
   - Setzen Sie einen Breakpoint bei der `addTask` Funktion, um den Inhalt des `Task` Objekts zu überprüfen:
     ```sh
     breakpoint set --name addTask
     continue
     print newTask
     ```

   - Durchlaufen Sie den Code Zeile für Zeile, um zu sehen, wie Variablen und Objekte sich ändern:
     ```sh
     next
     print tasks
     step
     finish
     ```

   - Überprüfen Sie die Inhalte der `tasks` und `milestones` Vektoren zu verschiedenen Zeitpunkten im Programm:
     ```sh
     print tasks
     print milestones
     ```
