#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

static volatile int loop = 1;

static void alrm_handler(int s)
{
  loop = 0;
}


int main()
{
  int64_t count = 0;
  alarm(5);
  signal(SIGALRM,alrm_handler);
  while(1)
    count++;

printf("%lld\n",count);

  exit(0);
}
