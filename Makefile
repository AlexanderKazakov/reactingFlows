CC=g++
CFLAGS=-std=c++11 -c -g -O0 -iquote.
LFLAGS=-lgsl -lgslcblas -g -O0
SRCDIR=src/
TESTDIR=test/
BUILDDIR=build/

MAINFILE=$(SRCDIR)main.cpp 
SOURCES=$(SRCDIR)NewtonMethod.cpp $(SRCDIR)util.cpp \
        $(SRCDIR)EquationSystem.cpp $(SRCDIR)GasDetonationSystem.cpp \
        $(SRCDIR)Reagent.cpp $(SRCDIR)Mixture.cpp $(SRCDIR)ConstMixture.cpp \
        $(SRCDIR)SystemToPlotHugoniotIsentropic.cpp \
        $(SRCDIR)SystemToPlotShockIsentropic.cpp \
        $(SRCDIR)ImplicitEulerMethod.cpp \
        $(SRCDIR)ImplicitEulerMethodSystem.cpp \
        $(SRCDIR)ZeldovichSystem.cpp
TESTS=$(TESTDIR)test.cpp $(TESTDIR)LinearEquationSystem.cpp \
      $(TESTDIR)NonLinearEquationSystem.cpp \
      $(TESTDIR)TestODESystem.cpp

MAINOBJ=$(MAINFILE:.cpp=.o)
OBJECTS=$(SOURCES:.cpp=.o)
TESTOBJS=$(TESTS:.cpp=.o)

EXECUTABLE=$(BUILDDIR)task1
TEST=$(BUILDDIR)test1

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS) $(MAINOBJ)
	$(CC) $(OBJECTS) $(MAINOBJ) -o $@ $(LFLAGS)

test: $(TEST)
	
$(TEST): $(TESTOBJS) $(OBJECTS)
	$(CC) $(TESTOBJS) $(OBJECTS) -o $@ $(LFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

exec: $(EXECUTABLE) $(TEST)
	./$(BUILDDIR)task1
	gnuplot plotter
	eog hugoniot.png

clean:   
	rm -f $(EXECUTABLE) $(TEST) $(OBJECTS) $(MAINOBJ) $(TESTOBJS) \
	residualError.txt HugoniotIsentropic.txt \ 
	rm -f hugoniot.png residualError.png hugoniotDeflagration.png \
	hugoniotDetonation.png
