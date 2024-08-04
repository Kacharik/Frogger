# Paths to include and library directories for FLTK and SFML
FLTK_INCLUDE_PATH = /opt/homebrew/include
FLTK_LIB_PATH = /opt/homebrew/lib
SFML_INCLUDE_PATH = /opt/homebrew/include
SFML_LIB_PATH = /opt/homebrew/lib

# Include directories for the project
SFML_INCLUDES = -I./src/ModelClasses -I$(SFML_INCLUDE_PATH)
FLTK_SFML_INCLUDES = -I./src/ModelClasses -I$(FLTK_INCLUDE_PATH) -I$(FLTK_INCLUDE_PATH)/FL -I$(SFML_INCLUDE_PATH)

# Libraries to link against
LIBS = -L$(FLTK_LIB_PATH) -lfltk -lfltk_images -L$(SFML_LIB_PATH) -lsfml-graphics -lsfml-window -lsfml-system

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Targets
all: frog

frog: src/FroggerModel.o src/FroggerView.o src/main.o src/ModelClasses/BoardView.o src/FroggerController.o src/ModelClasses/Frog.o src/ModelClasses/Rectangle.o src/ModelClasses/Lane.o src/ModelClasses/Heart.o
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -o frog src/FroggerModel.o src/FroggerView.o src/main.o src/ModelClasses/BoardView.o src/FroggerController.o src/ModelClasses/Frog.o src/ModelClasses/Rectangle.o src/ModelClasses/Lane.o src/ModelClasses/Heart.o $(LIBS)

src/FroggerModel.o: src/FroggerModel.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/FroggerModel.cpp -o src/FroggerModel.o

src/FroggerView.o: src/FroggerView.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/FroggerView.cpp -o src/FroggerView.o

src/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/main.cpp -o src/main.o

src/ModelClasses/BoardView.o: src/ModelClasses/BoardView.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/ModelClasses/BoardView.cpp -o src/ModelClasses/BoardView.o

src/FroggerController.o: src/FroggerController.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/FroggerController.cpp -o src/FroggerController.o

src/ModelClasses/Frog.o: src/ModelClasses/Frog.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/ModelClasses/Frog.cpp -o src/ModelClasses/Frog.o

src/ModelClasses/Rectangle.o: src/ModelClasses/Rectangle.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/ModelClasses/Rectangle.cpp -o src/ModelClasses/Rectangle.o

src/ModelClasses/Lane.o: src/ModelClasses/Lane.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/ModelClasses/Lane.cpp -o src/ModelClasses/Lane.o

src/ModelClasses/Heart.o: src/ModelClasses/Heart.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDES) -c src/ModelClasses/Heart.cpp -o src/ModelClasses/Heart.o

clean:
	rm -f src/*.o src/ModelClasses/*.o frog
