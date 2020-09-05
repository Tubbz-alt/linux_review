#include<stdio.h>

int Add(int num1, int num2)
{
  while (num2 != 0) {
    int c = ((num1 & num2)) << 1;
    num1 ^= num2;
    num2 = c;

  }
  return num1;

}


int main()
{

  int num1 = 9;
  int  num2 = 99;
  printf("%3d",Add(num1,num2));

  return 0;
}
