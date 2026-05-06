#include "types.h"
#include "user.h"

int
main(void)
{
  int pid;
  pid = fork();
  if(pid < 0){
    printf(1, "fork failed\n");
    exit();
  }
  if(pid == 0){  // 子进程
    int i;
    for(i=0; i<30; i++)
      write(1, "child\n", 6);
    exit();
  } else {       // 父进程
    int i;
    for(i=0; i<30; i++)
      write(1, "parent\n", 7);
    wait();
    exit();
  }
}
