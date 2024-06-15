# C++ Challenge: "Projektmanagementsystem"

## Ziel

Entwickle ein kleines Projektmanagementsystem in C++, das Aufgaben und Meilensteine verwaltet. Dieses Projekt wird dir helfen, wichtige Programmier- und Projektmanagementfähigkeiten zu erlernen und zu vertiefen.


```bash
# Verzeichnisstruktur
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
cd project-management-system
make clean
make
./project_management_system
make test
./run_tests

# VSCode-Editor
Ausführen und debuggen (Shift+Command+D)
```

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
   (lldb) target create "./project_management_system"
   (lldb) breakpoint set --name main
   ```

4. **Programm ausführen**:
   ```sh
   (lldb) run
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
   (lldb) next
   ```

6. **Variablen überprüfen**:
   Verwenden Sie den `print` Befehl, um den Wert von Variablen zu überprüfen.
   ```sh
   (lldb) print tasks
   (lldb) print milestones
   ```

7. **Quellcode anzeigen**:
   Um den aktuellen Quellcode anzuzeigen:
   ```sh
   (lldb) source list
   ```

### Debugging-Tipps

- **Setzen Sie Breakpoints strategisch**: Setzen Sie Breakpoints an Stellen, an denen Sie den Programmfluss und die Variablen überprüfen möchten.
  ```sh
  (lldb) breakpoint set --name addTask
  ```

- **Verwenden Sie `next` und `step` sinnvoll**: Verwenden Sie `next`, um die nächste Zeile auszuführen, und `step`, um in Funktionen einzutreten.
  ```sh
  (lldb) next
  (lldb) step
  ```
  
### Beispiel-Debugging-Sitzung

1. **Programm starten und bis zum `main` Breakpoint laufen lassen**:
   ```sh
   lldb ./project_management_system
   (lldb) target create "./project_management_system"
   (lldb) breakpoint set --name main
   (lldb) run
   ```

2. **Schrittweise durch den Code gehen und Variablen überprüfen**:
   ```sh
   (lldb) next
   (lldb) print tasks
   (lldb) next
   (lldb) print milestones
   (lldb) step
   (lldb) print newTask
   (lldb) finish
   (lldb) print tasks
   ```

3. **Untersuchung und Analyse**:
   - Setzen Sie einen Breakpoint bei der `addTask` Funktion, um den Inhalt des `Task` Objekts zu überprüfen:
     ```sh
     (lldb) breakpoint set --name addTask
     (lldb) continue
     (lldb) print newTask
     ```

   - Durchlaufen Sie den Code Zeile für Zeile, um zu sehen, wie Variablen und Objekte sich ändern:
     ```sh
     (lldb) next
     (lldb) print tasks
     (lldb) step
     (lldb) finish
     ```

   - Überprüfen Sie die Inhalte der `tasks` und `milestones` Vektoren zu verschiedenen Zeitpunkten im Programm:
     ```sh
     (lldb) print tasks
     (lldb) print milestones
     ```
