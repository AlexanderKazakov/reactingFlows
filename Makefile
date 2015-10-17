CC=g++
CFLAGS=-std=c++11 -c -g
OBJDIR=src/
SOURCES=$(OBJDIR)main.cpp $(OBJDIR)NewthonMethod.cpp \
$(OBJDIR)EquationSystem.cpp $(OBJDIR)GasDetonationSystem.cpp \
$(OBJDIR)Reagent.cpp $(OBJDIR)Mixture.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=task1

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -lgsl 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:   
	rm -f $(EXECUTABLE) $(OBJECTS)