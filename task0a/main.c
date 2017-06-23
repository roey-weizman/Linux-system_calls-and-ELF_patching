#include "lab4_util.h"

#define SYS_WRITE 4
#define STDOUT 1

int main (int argc , char* argv[])
{

  system_call(SYS_WRITE,STDOUT,"Hello World\n", 12);

  return 0;
}
