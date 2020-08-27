#include<iostream>

using namespace std;

struct stud{
short int age;
char num[3];
float s[2];
double ave;
}b,p;



int main()
{
  int x = 6;
  x += x -= x*x;
  cout<<"x = "<<x<<endl; 
  cout<<"b = "<<sizeof(b)<<endl;
  return 0;
}
