#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main( )
{ 
int i = 0;
for(i ;i < 2;++i)
{
  fork();
}
  printf("H\n");



}
