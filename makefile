# Paths to include and library directories for FLTK and SFML
FLTK_INCLUDE_PATH = /opt/homebrew/include
FLTK_LIB_PATH = /opt/homebrew/lib
SFML_INCLUDE_PATH = /opt/homebrew/include
SFML_LIB_PATH = /opt/homebrew/lib

# Include directories for the project
INCLUDES = -I./src -I./src/ModelClasses -I./src/Levels -I./src/Lanes -I./src/Screens -I$(FLTK_INCLUDE_PATH) -I$(FLTK_INCLUDE_PATH)/FL -I$(SFML_INCLUDE_PATH)

# Libraries to link against
LIBS = -L$(FLTK_LIB_PATH) -lfltk -lfltk_images -L$(SFML_LIB_PATH) -lsfml-graphics -lsfml-window -lsfml-system

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -O0

# Object files
OBJ_FILES = src/FroggerModel.o src/FroggerView.o src/main.o src/FroggerController.o \
            src/ModelClasses/Frog.o src/ModelClasses/Rectangle.o src/Lanes/Lane.o \
            src/ModelClasses/Heart.o src/ModelClasses/Car.o src/ModelClasses/Log.o \
            src/ModelClasses/Turtle.o  src/ModelClasses/Truck.o src/Lanes/LaneObject.o src/Screens/IntroScreen.o \
            src/Screens/VictoryScreen.o src/Screens/DefeatScreen.o src/Screens/MenuScreen.o \
            src/Levels/Level.o

# Targets
all: frog

frog: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o frog $(OBJ_FILES) $(LIBS)

# Rules for compiling object files
src/FroggerModel.o: src/FroggerModel.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/FroggerModel.cpp -o src/FroggerModel.o

src/FroggerView.o: src/FroggerView.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/FroggerView.cpp -o src/FroggerView.o

src/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/main.cpp -o src/main.o

src/FroggerController.o: src/FroggerController.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/FroggerController.cpp -o src/FroggerController.o

src/Screens/MenuScreen.o: src/Screens/MenuScreen.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Screens/MenuScreen.cpp -o src/Screens/MenuScreen.o

src/ModelClasses/Frog.o: src/ModelClasses/Frog.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Frog.cpp -o src/ModelClasses/Frog.o

src/ModelClasses/Rectangle.o: src/ModelClasses/Rectangle.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Rectangle.cpp -o src/ModelClasses/Rectangle.o

src/Lanes/Lane.o: src/Lanes/Lane.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Lanes/Lane.cpp -o src/Lanes/Lane.o

src/ModelClasses/Heart.o: src/ModelClasses/Heart.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Heart.cpp -o src/ModelClasses/Heart.o

src/ModelClasses/Car.o: src/ModelClasses/Car.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Car.cpp -o src/ModelClasses/Car.o

src/ModelClasses/Log.o: src/ModelClasses/Log.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Log.cpp -o src/ModelClasses/Log.o

src/ModelClasses/Turtle.o: src/ModelClasses/Turtle.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Turtle.cpp -o src/ModelClasses/Turtle.o

src/ModelClasses/Truck.o: src/ModelClasses/Truck.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/ModelClasses/Truck.cpp -o src/ModelClasses/Truck.o

src/Lanes/LaneObject.o: src/Lanes/LaneObject.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Lanes/LaneObject.cpp -o src/Lanes/LaneObject.o

src/Screens/IntroScreen.o: src/Screens/IntroScreen.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Screens/IntroScreen.cpp -o src/Screens/IntroScreen.o

src/Screens/VictoryScreen.o: src/Screens/VictoryScreen.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Screens/VictoryScreen.cpp -o src/Screens/VictoryScreen.o

src/Screens/DefeatScreen.o: src/Screens/DefeatScreen.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Screens/DefeatScreen.cpp -o src/Screens/DefeatScreen.o

src/Levels/Level.o: src/Levels/Level.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Levels/Level.cpp -o src/Levels/Level.o

clean:
	rm -f src/*.o src/ModelClasses/*.o src/Levels/*.o src/Lanes/*.o src/Screens/*.o frog
