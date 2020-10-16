CXX = g++
CXX_FLAGS = -g -O2
INCLUDES = -I/cygdrive/d/glm/

SRCS = $(wildcard src/*.cc) $(wildcard src/core/*.cpp) $(wildcard src/util/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

.PHONY: shiny_demo

shiny_demo: $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o bin/shiny $(INCLUDES)

src/%.o: src/%.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@ $(INCLUDES)

src/core/%.o: src/core/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@ $(INCLUDES)

src/util/%.o: src/util/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@ $(INCLUDES)



