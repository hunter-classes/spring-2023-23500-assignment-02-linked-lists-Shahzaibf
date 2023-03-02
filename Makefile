main: main.o list.o node.o
	g++ -o main main.o list.o node.o

main.o: main.cpp list.o node.o
	g++ -c main.cpp

list.o: list.cpp list.h

node.o: node.cpp node.h

clean:
	rm -f main *.o