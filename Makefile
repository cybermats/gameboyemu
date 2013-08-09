CXX = g++
CXXFLAGS ?= -g -Wall -W -Winline 
LDFLAGS ?=
RM = rm
INCLUDES = 
LIBS =

TESTLIBS = $(LIBS) -lUnitTest++

.SUFFIXES: .o .cpp

test = testgbemu
main = gbemu

src = cpu.cpp \
	mmu.cpp


test_src = testmain.cpp \
	testcpu.cpp

main_src = main.cpp

objects = $(src:.cpp=.o)
test_objects = $(test_src:.cpp=.o)
main_objects = $(main_src:.cpp=.o)

.PHONY: depend clean

all: $(main) $(test)
	@echo All built

main: $(main)
	@echo Built main

test: $(test)
	@echo Built tests

$(main): $(objects) $(main_objects)
	@echo Linking $@ ...
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS)

$(test): $(objects) $(test_objects)
	@echo Linking $@ ...
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(TESTLIBS)

.cpp.o:
	@echo $<
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	@echo Cleaning...
	-@$(RM) -f *.o *~ $(main) 2> /dev/null


depend: $(src) $(main_src) $(test_src)
	makedepend $(INCLUDES) $^

# DO NOT DELETE

cpu.o: cpu.hpp mmu.hpp
mmu.o: mmu.hpp
main.o: cpu.hpp mmu.hpp
testmain.o: /usr/include/UnitTest++/UnitTest++.h
testmain.o: /usr/include/UnitTest++/Config.h /usr/include/UnitTest++/Test.h
testmain.o: /usr/include/UnitTest++/TestDetails.h
testmain.o: /usr/include/UnitTest++/TestList.h
testmain.o: /usr/include/UnitTest++/TestSuite.h
testmain.o: /usr/include/UnitTest++/TestResults.h
testmain.o: /usr/include/UnitTest++/TestMacros.h
testmain.o: /usr/include/UnitTest++/ExecuteTest.h
testmain.o: /usr/include/UnitTest++/MemoryOutStream.h
testmain.o: /usr/include/UnitTest++/AssertException.h
testmain.o: /usr/include/UnitTest++/CurrentTest.h
testmain.o: /usr/include/UnitTest++/CheckMacros.h
testmain.o: /usr/include/UnitTest++/Checks.h
testmain.o: /usr/include/UnitTest++/TestRunner.h
testmain.o: /usr/include/UnitTest++/TimeConstraint.h
testmain.o: /usr/include/UnitTest++/TimeHelpers.h
