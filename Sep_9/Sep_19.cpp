#include<iostream>

using namespace std;


class A
{
  public:
    virtual void func(int val = 1)
    { std::cout<<"A->"<<val <<std::endl; }
    virtual void test()
    { func(); }

};
class B : public A
{
  public:
    void func(int val=0)
    {std::cout<<"B->"<<val <<std::endl;}

};
int main(int argc ,char* argv[])
{
  B*p = new B;
  p->test();
  return 0;

}
/*
记住：virtual 函数是动态绑定，而缺省参数值却是静态绑定。 意思是你可能会 在“调用一个定义于派生类内的virtual函数”的同时，却使用基类为它所指定的缺省参数值。
结论：绝不重新定义继承而来的缺省参数值！（可参考《Effective C++》条款37）
对于本例：
复制代码
1
2
3
B*p = newB;

p->test();
p->test()执行过程理解：
(1) 由于B类中没有覆盖（重写）基类中的虚函数test()，因此会调用基类A中的test()；
(2) A中test()函数中继续调用虚函数 fun()，因为虚函数执行动态绑定，p此时的动态类型（即目前所指对象的类型）为B*，因此此时调用虚函数fun()时，执行的是B类中的fun()；所以先输出“B->”；
(3) 缺省参数值是静态绑定，即此时val的值使用的是基类A中的缺省参数值，其值在编译阶段已经绑定，值为1，所以输出“1”；
最终输出“B->1”。所以大家还是记住上述结论：绝不重新定义继承而来的缺省参数值！
*/




























