# Definiere den Compiler und die Compiler-Flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -Iinclude

# Definiere die Quell- und Objektdateien
SRCS = src/main.cpp src/Task.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = project_management

# Standardziel
all: $(TARGET)

# Ziel zum Erstellen des ausführbaren Programms
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Musterregel zum Kompilieren der .cpp-Dateien in .o-Dateien
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ziel zum Bereinigen des Projekts
clean:
	rm -f $(OBJS) $(TARGET)

# Füge ein Phony-Ziel hinzu, um Konflikte mit Dateinamen zu vermeiden
.PHONY: all clean
