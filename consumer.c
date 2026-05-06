#include "types.h"
#include "user.h"

int
main(void)
{
  int i, val;
  for(i = 0; i < 20; i++){
    val = scconsume();
    printf(1, "consumer got %d\n", val);
  }
  exit();
}

