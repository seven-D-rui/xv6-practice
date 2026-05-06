#include "types.h"
#include "user.h"

int
main(void)
{
  int i;
  for(i = 0; i < 20; i++){
    printf(1, "producer calling with %d\n", i);
    spproduce(i);
  }
  exit();
}
