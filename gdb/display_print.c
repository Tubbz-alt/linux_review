#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TAG_datastruct
{
  char* string;
  int checksum;
}datastruct;

datastruct* getinput(void);

void printmessage(datastruct *todisp);


int main()
{
  int counter;
  int maxval = 0;

  datastruct *svalues[200];

  for(counter = 0;counter < 200;++counter)
  {
    svalues[counter] = getinput();
    if(!svalues[counter])
      break;
   maxval = counter;
  }
  printmessage(svalues[maxval/2]);
  return 0;
}
datastruct* getinput(void)
{
  char input[80];
  datastruct *instruct;
  int counter;
  
  printf("Enter a string,or leave blank when done:\n");
  fgets(input,79,stdin); 

}
void printmessage(datastruct *todisp)
{

}
