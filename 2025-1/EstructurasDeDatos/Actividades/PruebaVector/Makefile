# Variables
SourcesDirectory = ./Sources
ObjectsDirectory = ./Objects
Sources = $(wildcard $(SourcesDirectory)/*.cpp)
Objects = $(patsubst $(SourcesDirectory)/%.cpp, $(ObjectsDirectory)/%.o, $(Sources))

# Compiler and Flags
CXX = g++

# Default Target
all: $(ObjectsDirectory) $(Objects) MainFile

# Rule to compile .cpp files into .o files in the build directory
$(ObjectsDirectory)/%.o: $(SourcesDirectory)/%.cpp
	@$(CXX) -c $< -o $@

# Rule to create the build directory
$(ObjectsDirectory):
	@mkdir -p $(ObjectsDirectory)

# Rule to compile the project
MainFile: 
	@$(CXX) $(Objects) -o main

# Clean up
clean:
	@rm -rf $(ObjectsDirectory)
	@rm main

