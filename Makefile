# Nadav034@gmail.com

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

SRCS_DEMO = Demo.cpp Graph.cpp Algorithms.cpp
OBJS_DEMO = $(SRCS_DEMO:.cpp=.o)
SRCS_TEST = Test.cpp Graph.cpp Algorithms.cpp
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
DEPS = Graph.hpp Algorithms.hpp
TARGET_DEMO = my_program
TARGET_TEST = test_program

all: $(TARGET_DEMO) $(TARGET_TEST)

# Rule to build the DEMO program
$(TARGET_DEMO): $(OBJS_DEMO)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DEMO) $(OBJS_DEMO)

# Rule to build the test program
$(TARGET_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(OBJS_TEST)

# Generic rule to build object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean the build
clean:
	rm -f $(OBJS_DEMO) $(OBJS_TEST) $(TARGET_DEMO) $(TARGET_TEST)
