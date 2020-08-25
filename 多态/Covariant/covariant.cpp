#include<iostream>

using namespace std;
class Base
{
  public:
      Base()
      {
            cout << "Base" << endl;
              
      }
        virtual void fun()
        {
              cout << "Base" << endl;
                
        }
          virtual Base* Test()
          {
                cout << "Base()" << endl;
                    return this;
                      
          }
  private:
            int m_a;
              int m_b;

};

class A :public Base
{
  public:
      A()
      {
            cout << "A" << endl;
              
      }
        void fun()
        {
              cout << "A" << endl;
                
        }
          A * Test()
          {
                cout << "A()" << endl;
                    return this;
                      
          }
  private:
            int a;
              int b;

};

int main()
{
    A a;
    Base *p = &a;  
    p->Test();
    return 0;

}
