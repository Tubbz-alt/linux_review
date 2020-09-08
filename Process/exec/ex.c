#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


int main()
{
  puts("Begin!"); 
  fflush(stdout);
  execl("/usr/bin/date","date","+%s",NULL);
  perror("execl()");
  exit(1);
  puts("End!");

  return 0;
}
