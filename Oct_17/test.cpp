#include<iostream>
#include<stdio.h>
using namespace std;

class A
{
  public:
    virtual void Test()
    {
      printf("A test\n");

    }

};
class B: public A
{
  public:
    void func()
    {
      Test();

    }
    virtual void Test()
    {
      printf("B test\n");

    }

};
class C: public B
{
  public:
    virtual void Test()
    {
      printf("C test\n");

    }

};
int main()
{
  C c;
  ((B *)(&c))->func();
  ((B)c).func();
  return 0;
}
