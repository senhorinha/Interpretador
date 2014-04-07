CC=g++
CFLAGS=-c -Wall -std=c++11 -O2
LDFLAGS=
SOURCES=src/model/Interpretador.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=interpretador

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@