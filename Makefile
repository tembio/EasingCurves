CC := g++ 
SRCDIR := src
BUILDDIR := build
TARGET := bin/EasingCurves
 
SRCEXT := cpp
OBJECTS := $(BUILDDIR)/main.o $(BUILDDIR)/EasingCurve.o $(BUILDDIR)/EasingCurveEvaluator.o
CFLAGS := -g # -Wall
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean