CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
HEADERS = $(wildcard include/*.h)
TARGET = refugio

# Para las pruebas se usan todos los .cpp menos main.cpp
SRC_LIB = $(filter-out src/main.cpp, $(SRC))
TEST = test_refugio

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: tests/test_refugio.cpp $(SRC_LIB) $(HEADERS)
	$(CXX) $(CXXFLAGS) tests/test_refugio.cpp $(SRC_LIB) -o $(TEST)
	./$(TEST)

clean:
	rm -f src/*.o $(TARGET) $(TARGET).exe $(TEST) $(TEST).exe
