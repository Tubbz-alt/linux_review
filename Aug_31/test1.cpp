#include<iostream>

using namespace std;

int main()
{
  int a=1,b=0,c=-1,d=0;
  d=++a||++b&&++c;
  cout<<d<<endl;
  return 0;

}
