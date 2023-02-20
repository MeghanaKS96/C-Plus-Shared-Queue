
all: sharedq.o main.o
	$(CXX) --std=c++17 -g -o main main.o sharedq.o

main.o:
	$(CXX) --std=c++17 -g -c main.cpp -o main.o
sharedq.o:
	$(CXX) --std=c++17 -g -c sharedq.cpp -o sharedq.o

clean:
	rm *.o main
