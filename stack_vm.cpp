#include "stack_vm.h"
#include <iostream>
#include <vector>


/*
 * Instruction Format
 * total_size= 32 bits
 * instruction header = 2 bits
 * data = 30 bits
 *
 * header format
 * 0 = positive
 * 1 = primitive instruction
 * 2 = postive
 * 3 = undefined
 */
stack_vm::stack_vm()
{
  memory.reserve(1000000);
}

  //int32 get_type(int32 instruction);
  //int32 get_data(int32 data);
  //void fetch();
  //void decode();
  //void execute();
  //void do_primitive();

//public:
  //stack_vm();
  //void run();
  //void load_program(std::vector<int32> prog);
int32 stack_vm::get_type(int32 instruction)
{
  // 0xc= 1100 
  return ((0xc0000000 & instruction)>>30);
}

int32 stack_vm::get_data(int32 data)
{
  return ((0x3fffffff & data));
}

void stack_vm::fetch()
{
  this->pc++;
}

void stack_vm::decode()
{
  type= get_type(memory[pc]);
  data= get_data(memory[pc]);
}

void stack_vm::execute()
{
  //type == integer
  if(type == 0 || type == 2)
  {
    sp++;
    memory[sp]= data;
  }
  else
  {
    do_primitive();
  }
}

void stack_vm::do_primitive()
{
  switch (data)
  {
    case 0: //halt
      std::cout << "halt"<< std::endl;
      running= 0;
      break;
    case 1://add
      std::cout<<"add" << memory[sp-1] <<"  "<<memory[sp] << std::endl;
      memory[sp -1] += memory[sp];
      break;
  
  }
}

void stack_vm::run()
{
  pc-= 1;
  while(running)
  {
    fetch();
    decode();
    execute();
    std::cout<<"tos" <<memory[sp]<<std::endl;
  }
}


void stack_vm::load_program(std::vector<int32> program)
{
  for(int32 i=0; i < program.size(); i++)
  {
    memory[pc+i]= program[i];
  }
}



















