#include "types.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "proc.h"

#define BUF_SIZE 8

int buffer[BUF_SIZE];
int head = 0;
int tail = 0;
int count = 0;
struct spinlock buflock;
