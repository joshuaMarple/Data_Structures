all:Lab06

Lab06: main.o min5heap.o
	g++ min5heap.o main.o -o Lab5

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

min5heap.o: min5heap.cpp
	g++ -c -g -std=c++11 min5heap.cpp

clean:
	rm *.o