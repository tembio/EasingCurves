CC := g++ 
SRCDIR := src
BUILDDIR := build
TARGET := bin/EasingCurves
 
SRCEXT := cpp
OBJECTS :=  $(BUILDDIR)/EasingCurve.o \
		    $(BUILDDIR)/LinearCurve.o \
		    $(BUILDDIR)/InQuadCurve.o \
		    $(BUILDDIR)/OutQuadCurve.o \
		    $(BUILDDIR)/InOutQuadCurve.o \
		    $(BUILDDIR)/ArcCurve.o \
		    $(BUILDDIR)/ArcYCurve.o \
		    $(BUILDDIR)/ArcXCurve.o \
		    $(BUILDDIR)/EasingCurveFactory.o \
		    $(BUILDDIR)/EasingCurveEvaluator.o
CFLAGS := -g -std=c++14# -Wall
INC := -I include
TESTSDIR := tests

$(TARGET): $(OBJECTS) $(BUILDDIR)/main.o
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) 
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tests: tests.o $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(BUILDDIR)/tests.o -o bin/tests

tests.o: 
	$(CC) $(CFLAGS) $(TESTSDIR)/tests.cpp $(INC) -c -o $(BUILDDIR)/tests.o

