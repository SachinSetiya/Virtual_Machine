#ifndef STACK_VM_H
#define STACK_VM_H


#include <bits/stdint-intn.h>
#include <iostream>
#include <vector>

//Do the typedefs

//TODO for now just do int_32
typedef int32_t int32;

class stack_vm
{
private:
  int32 pc= 100; //programe counter //wtf
  int32 sp= 0; //stack pointer
  std::vector<int32> memory;
  int32 type= 0;
  int32 data= 0;
  int32 running= 0;

  int32 get_type(int32 instruction);
  int32 get_data(int32 data);
  void fetch();
  void decode();
  void execute();
  void do_primitive();

public:
  stack_vm();
  void run();
  void load_program(std::vector<int32> prog);
  
};

#endif //STACK_VM_H
