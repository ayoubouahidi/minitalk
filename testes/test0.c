#include <signal.h>
#include <stdlib.h>

int main()
{
  int *n = malloc(sizeof(int));
  *n = 10;
  signal(10, signal(20, (__sighandler_t)30)); // ovalley's code 
}
