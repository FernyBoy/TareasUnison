# Compiler and Flags
LUA = lualatex
ZAT = zathura

# Default Target
all: Compile MainFile

# Rule to create the build directory
Compile:
	@$(LUA) *.tex

# Rule to compile the project
MainFile: 
	@$(ZAT) *.pdf &

