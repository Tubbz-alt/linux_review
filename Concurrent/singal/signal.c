#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>

static void Inturput_Handlle(int s)
{
  write(1,"!",1);
}



int main()
{
  int i;
  signal(SIGINT,Inturput_Handlle);
  //signal(SIGINT,)
  for(i = 0;i < 10;++i)
  {
    write(1,"*",1);
    sleep(1);
  }

  return 0;
}
