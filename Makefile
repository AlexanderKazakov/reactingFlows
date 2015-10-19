CC=g++
CFLAGS=-std=c++11 -c -g -O0 -iquote.
LFLAGS=-lgsl -lgslcblas -g -O0
SRCDIR=src/
TESTDIR=test/

MAINFILE=$(SRCDIR)main.cpp 
SOURCES=$(SRCDIR)NewthonMethod.cpp $(SRCDIR)util.cpp \
        $(SRCDIR)EquationSystem.cpp $(SRCDIR)GasDetonationSystem.cpp \
        $(SRCDIR)Reagent.cpp $(SRCDIR)Mixture.cpp
TESTS=$(TESTDIR)test.cpp $(TESTDIR)LinearEquationSystem.cpp \
      $(TESTDIR)NonLinearEquationSystem.cpp

MAINOBJ=$(MAINFILE:.cpp=.o)
OBJECTS=$(SOURCES:.cpp=.o)
TESTOBJS=$(TESTS:.cpp=.o)

EXECUTABLE=task1
TEST=test1

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS) $(MAINOBJ)
	$(CC) $(OBJECTS) $(MAINOBJ) -o $@ $(LFLAGS)

test: $(TEST)
	
$(TEST): $(TESTOBJS) $(OBJECTS)
	$(CC) $(TESTOBJS) $(OBJECTS) -o $@ $(LFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:   
	rm -f $(EXECUTABLE) $(TEST) $(OBJECTS) $(MAINOBJ) $(TESTOBJS)
