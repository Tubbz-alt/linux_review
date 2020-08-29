#include<iostream>

using namespace std;

/*
class Base
{
      public:
            void virtual Func()
            {
                      cout<<"Base"<<endl;
                          
            }

};
  
class Derived : public Base
{
      public:
            void virtual Func()
            {
                      cout<<"Derived "<<endl;
                          
            }

};
  
int main ()
{
      Base* pBase = new Base();
          pBase ->Func();
              Derived * pDerived = (Derived*)pBase;
                  pDerived->Func();
                      delete pBase;
                        
                          pDerived  =  new Derived();
                              pBase = pDerived;
                                  pBase->Func();
                                    
                                      delete pDerived;
                                            return 0;

}  



class Base
{
  public:
      void fun()
      {
            cout << "Base" << endl;
              
      }
      Base()
      {
        cout<<"Base"<<endl;
      }
     virtual ~Base()
        {
              cout << "~Base" << endl;
                
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
              cout << "fun" << endl;
                
        }
          ~A()
          {
                cout << "~A" << endl;
                  
          }
            void print()
            {
                  cout << "print" << endl;
                    
            }
  private:
              int a;
                int b;

};


int main()
{
    Base* p = new A();  //动态申请需要手动释放
      delete p;
      return 0;

}

*/

class ClassA
{
  public:
        virtual ~ ClassA(){};
            virtual void FunctionA(){};

};
class ClassB
{
  public:
       virtual void FunctionB(){};

};
class ClassC : public ClassA,public ClassB
{
      public:

};
  

int main()
{
 ClassC aObject;
 ClassA* pA=&aObject;
 ClassB* pB=&aObject;                                                                                                                                               
 ClassC* pC=&aObject;
 cout<<"PA = "<<pA <<"PB = "<<pB<<"pC = "<<pC<<endl;
  return 0;
}














