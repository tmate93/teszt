OBJS := Szorny.o Kalandor.o Jsonparser.o Source.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++

CPPFILES := Szorny.cpp Kalandor.cpp Jsonparser.cpp Source.cpp
CPPCFLAGS := --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi

TESTFILES:= Units/Arnykiraly.json Units/Sotetvarazslo.json
VLGRNDFLAGS:= --leak-check=full --error-exitcode=3
VLGRNDPARAM:=  ./output $(TESTFILES)

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

Szorny.o: Szorny.cpp
	$(CC) $(CFLAGS) Szorny.cpp

Kalandor.o: Kalandor.cpp
	$(CC) $(CFLAGS) Kalandor.cpp

Jsonparser.o: Jsonparser.cpp
	$(CC) $(CFLAGS) Jsonparser.cpp

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

