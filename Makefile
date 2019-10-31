CC=g++
CFLAGS=-std=c++1y -I -Wall -g

ODIR=obj

LIBS= -lboost_program_options -lboost_unit_test_framework

_DEPS = options.h executor.h fileOperation.h

.PHONY: all test run clean
all: tox test
 
$(ODIR)/%.o: %.cpp $(_DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

_SHARED_OBJ = options.o executor.o fileOperation.o
_OBJ = main.o $(_SHARED_OBJ)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

tox: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

_TESTOBJ = test.o $(_SHARED_OBJ)
TESTOBJ = $(patsubst %,$(ODIR)/%,$(_TESTOBJ))

test: $(TESTOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run:  test
	./test

clean:
	rm -rf $(ODIR) tox test