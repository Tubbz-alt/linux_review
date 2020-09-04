#include<iostream>

using namespace std;
/*
   class XBase
   {
   public:
   virtual void play()const
   {
   cout<<"base play"<<endl;

   }

   };

   class XWind:public XBase
   {
   public:
   void play()
   {
   cout<<"wind play"<<endl;

   }

   };

   class XBrass:public XWind
   {
   public:
   void play()
   {
   cout<<"brass play"<<endl;

   }

   };

   void Tune(XBase& b)
   {
   b.play();
   }


   int main()
   {
   XBase* base[] = {new XWind(),new XBrass()};

   for(int i = 0;i < 2;i++)
   {
   Tune(*base[i]);

   }
   return 0;

   }*/


#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void print() const = 0;

};

class Test : public Base
{
  public:
    void print();
    void print() const;

};

void Test::print()
{
  cout << "Test::print()" << endl;

}

void Test::print() const
{
  cout << "Test::print() const" << endl;

}

int main()
{
  Base* pChild = new Test();
  pChild->print();

  const Test  obj;
  obj.print();

  Test obj1;
  obj1.print();

  Test* pOwn = new Test();
  pOwn->print();
  return 0;
}

























