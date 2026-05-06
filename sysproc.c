#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_hello(void)
{
  cprintf("Hello from kernel!\n");
  return 0;
}
int
sys_spproduce(void)
{
  int val;
  if(argint(0, &val) < 0)
    return -1;

  acquire(&buflock);
  while(count == BUF_SIZE){
    sleep(&buffer, &buflock);
  }
  buffer[tail] = val;
  tail = (tail + 1) % BUF_SIZE;
  count++;
  cprintf("produced %d, count=%d\n", val, count);
  wakeup(&buffer);
  release(&buflock);
  return 0;
}

int
sys_scconsume(void)
{
  int val;
  acquire(&buflock);
  while(count == 0){
    sleep(&buffer, &buflock);
  }
  val = buffer[head];
  head = (head + 1) % BUF_SIZE;
  count--;
  cprintf("consumed %d, count=%d\n", val, count);
  wakeup(&buffer);
  release(&buflock);
  return val;
}
int
sys_spproduce(void)
{
  int val;
  if(argint(0, &val) < 0)
    return -1;

  acquire(&buflock);
  while(count == BUF_SIZE){
    sleep(&buffer, &buflock);
  }
  buffer[tail] = val;
  tail = (tail + 1) % BUF_SIZE;
  count++;
  cprintf("produced %d, count=%d\n", val, count);
  wakeup(&buffer);
  release(&buflock);
  return 0;
}

int
sys_scconsume(void)
{
  int val;
  acquire(&buflock);
  while(count == 0){
    sleep(&buffer, &buflock);
  }
  val = buffer[head];
  head = (head + 1) % BUF_SIZE;
  count--;
  cprintf("consumed %d, count=%d\n", val, count);
  wakeup(&buffer);
  release(&buflock);
  return val;
}
