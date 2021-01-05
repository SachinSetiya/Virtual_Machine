#include "stack_vm.h"

int main()
{
  stack_vm vm;
  std::vector<int32> progarm{ 3, 4, 0x40000001, 0x40000000};
  vm.load_program(progarm);
  vm.run();
  return 0;
}
