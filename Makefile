OBJS := Jsonparser.o Szorny.o Kalandor.o Source.o
CFLAGS := -std=c++17 -Wall -Wextra -g
CC := g++

CPPFILES := Jsonparser.cpp Szorny.cpp Kalandor.cpp Source.cpp
CPPCFLAGS := --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi

TESTFILES:= Units/Arnykiraly.json Units/Sotetvarazslo.json
VLGRNDFLAGS:= --leak-check=full --error-exitcode=3
VLGRNDPARAM:=  ./output $(TESTFILES)

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

Jsonparser.o: Jsonparser.cpp
	$(CC) $(CFLAGS) Jsonparser.cpp

Szorny.o: Szorny.cpp
	$(CC) $(CFLAGS) Szorny.cpp

Kalandor.o: Kalandor.cpp
	$(CC) $(CFLAGS) Kalandor.cpp

Source.o: Source.cpp
	$(CC) $(CFLAGS) Source.cpp

cppcheck:
	cppcheck $(CPPFILES) $(CPPCFLAGS)

valgrind:
	valgrind $(VLGRNDFLAGS) $(VLGRNDPARAM)
	
unittest:
	cd tests && ./runTests

doc: 
	doxygen doxconf

clean:
	rm -rf *.o add ./html ./latex

