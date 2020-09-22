#include<stdio.h>
#include<time.h>

int main()
{
  time_t bigggest = 0x7FFFFFFF;
  printf("bigggest = %s\n",ctime(&bigggest));
  return 0;
}
