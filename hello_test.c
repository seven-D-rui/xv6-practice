#include "types.h"
#include "user.h"

int
main(void)
{
  printf(1, "Calling hello syscall...\n");
  hello();
  printf(1, "Done.\n");
  exit();
}
