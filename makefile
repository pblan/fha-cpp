# author: a.voss@fh-aachen.de

# Which compiler to use
#CXX = g++
CXX = clang++

# What flags should be passed to the compiler
CXXFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -pthread -std=c++17

# What flags should be passed to the linker
LDFLAGS = -lm

# collect  files
CXXEXAMPLES = $(shell find . -name '*.cpp' -print -type f)
CXXTARGETS = $(foreach file, $(CXXEXAMPLES), ./$(file:.cpp=.out))

# when just invoking make (no parameters), make will build the first target 
# build them all
all: $(CXXTARGETS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS)  $< $(LDFLAGS) -o $@

clean:
	rm out/*