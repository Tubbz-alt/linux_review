#include<stdio.h>
#include<unistd.h>

int main()
{
  fork();
  printf("hello\n");
  fork();
  printf("hello\n");
  while(1);
  return 0;
}

