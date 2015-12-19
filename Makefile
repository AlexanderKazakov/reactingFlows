CC=g++
CFLAGS=-std=c++11 -c -iquote. -O3
LFLAGS=-lgsl -lgslcblas -O3
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
TESTMAIN=$(TESTDIR)test.cpp 
TESTS=$(TESTDIR)LinearEquationSystem.cpp \
      $(TESTDIR)NonLinearEquationSystem.cpp \
      $(TESTDIR)TestODESystem.cpp

MAINOBJ=$(MAINFILE:.cpp=.o)
TESTMAINOBJ=$(TESTMAIN:.cpp=.o)
OBJECTS=$(SOURCES:.cpp=.o)
TESTOBJS=$(TESTS:.cpp=.o)

EXECUTABLE=$(BUILDDIR)task1
TEST=$(BUILDDIR)test1

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS) $(TESTOBJS) $(MAINOBJ)
	$(CC) $(OBJECTS) $(TESTOBJS) $(MAINOBJ) -o $@ $(LFLAGS)

test: $(TEST)
	
$(TEST): $(TESTOBJS) $(OBJECTS) $(TESTMAINOBJ)
	$(CC) $(TESTOBJS) $(OBJECTS) $(TESTMAINOBJ) -o $@ $(LFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

exec: $(EXECUTABLE) $(TEST)
	./$(BUILDDIR)task1
	gnuplot plotter
	eog hugoniot.png

exec2: $(EXECUTABLE) $(TEST)
	./$(BUILDDIR)task1
	gnuplot task2plotter
	eog ZeldovichPRho.png

clean:   
	rm -f $(EXECUTABLE) $(TEST) $(OBJECTS) $(MAINOBJ) $(TESTOBJS) $(TESTMAINOBJ) \
	residualError.txt HugoniotIsentropic.txt \ 
	rm -f hugoniot.png residualError.png hugoniotDeflagration.png \
	hugoniotDetonation.png
	rm -f ZeldovichUZ.png ZeldovichPRho.png ZeldovichT.png Zeldovich.txt
