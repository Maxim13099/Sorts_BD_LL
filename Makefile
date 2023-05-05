all: main.o realize.o sqlite3.o base_sqlite.o sorts.o LinkedList.o
	g++ main.o realize.o sqlite3.o base_sqlite.o sorts.o LinkedList.o -o all -ldl -lpthread
	
main.o: main.cpp
	g++ -c main.cpp
	
sqlite3.o: sqlite3.c
	gcc -c sqlite3.c -ldl -lpthread
	
base_sqlite.o: base_sqlite.cpp
	g++ -c base_sqlite.cpp
	
sorts.o: sorts.cpp
	g++ -c sorts.cpp

realize.o: realize.cpp
	g++ -c realize.cpp
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

clean:
	rm -rf *.o *.exe
