# compiler
CXX=g++
#flags
CXXFLAGS := -Wall

SRC := src
OBJ := obj

SOURCES := $(shell find $(SRC)/ -type f -name '*.cpp')
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
DEPENDS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.d, $(SOURCES))
EXECUTABLE := automate

.PHONY: all clean executable

# default
all:$(EXECUTABLE)

executable : $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CXX) -o $(EXECUTABLE) $^ $(CXXFLAGS)

-include $(DEPENDS)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(WARNING) $(CXXFLAGS)

clean:
	rm -rf $(OBJ) $(EXECUTABLE)