#include<iostream>
#include<string>
#include<memory>
using namespace std;

int main()
{
  //string * p = new string[10]();
  int* p = new int[10];
  
  auto_ptr<int> ptr(p);

  return 0;
}
