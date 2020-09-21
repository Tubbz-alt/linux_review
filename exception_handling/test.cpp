#include<iostream>

using namespace std;

/*
int Modify(int a,int b)
{
  if(b == 0)
    throw b;
  return a/b;
}
int main()
{
  try{
    Modify(10,0);
  }
  catch(int)
  {
      cout<<"Error ,modify zero"<<endl;
  }
  return 0;
}
*/



int Modify(int a,int b)
{
  double pi = 3.14;
  if(b == 0)
    throw pi;
  return a/b;
}
int main()
{
  try{
    Modify(10,0);
  }
  catch(int)
  {
      cout<<"Error ,modify zero"<<endl;
  }
  catch(...)
  {
    cout<<"Return Error"<<endl;
  }
  return 0;
}
















