CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -pedantic -g
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(filter-out $(TEST_DIR)/test_main.cpp, $(TEST_FILES)))

EXECUTABLE = project_management_system
TEST_EXECUTABLE = run_tests

.PHONY: all clean build test

all: build

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	@echo "Linking $(EXECUTABLE)"
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $@ -c $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE) $(TEST_EXECUTABLE)

test: $(BUILD_DIR)/test_main.o $(TEST_OBJ_FILES) $(SRC_OBJ_FILES)
	@echo "Linking $(TEST_EXECUTABLE)"
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $(TEST_EXECUTABLE) $^ -lCatch2
	./$(TEST_EXECUTABLE)
