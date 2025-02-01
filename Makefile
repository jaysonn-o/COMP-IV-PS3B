CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g -Werror
LDFLAGS = $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

OBJS = main.o Universe.o CelestialBody.o
TEST_OBJS = test.o

# Default target (build both NBody and test)
all: NBody test

# Target for the main executable
NBody: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o NBody $(LDFLAGS)
	ar rcs NBody.a $(OBJS)

# Target for the unit test executable
test: $(TEST_OBJS) Universe.o CelestialBody.o
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) Universe.o CelestialBody.o -o test $(LDFLAGS)

# Generic rule for compiling C++ source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TEST_OBJS) NBody NBody.a test
