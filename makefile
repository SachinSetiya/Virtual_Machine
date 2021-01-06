CFLAGS=-g -std=c++11

all: stack_vm

stack_vm: stack_vm.o main.o
	$(CXX) $(CFLAGS) stack_vm.o main.o -o stack_vm

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

stack_vm.o: stack_vm.h stack_vm.cpp
	$(CXX) $(CFLAGS) -c stack_vm.cpp

clean:
	rm -rf *.o stack_vm
