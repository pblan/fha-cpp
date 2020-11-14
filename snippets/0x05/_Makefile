# author: a.voss@fh-aachen.de

# compiler settings
CXX = g++
# CXX = clang++
CXXFLAGS = -ansi -pedantic -Wall -Wextra -Wconversion -pthread -std=c++2a
LDFLAGS = -lm

# collect  files
CXXEXAMPLES = $(shell find . -name '*.cpp' -print -type f)
CXXTARGETS = $(foreach file, $(CXXEXAMPLES), ./$(file:.cpp=.out))

# build them all
all: $(CXXTARGETS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS)  $< $(LDFLAGS) -o $@

clean:
	rm *.out
