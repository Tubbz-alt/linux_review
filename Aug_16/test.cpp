#include<iostream>

using namespace std;
struct Ca {
    ~Ca(void)
    {
          cout << "~Ca" << endl;
            
    }

};
struct Cb {
    ~Cb(void)
    {
          cout << "~Cb" << endl;
            
    }

};
struct Cc {
    ~Cc(void)
    {
          cout << "~Cc" << endl;
            
    }

};
struct Cd : virtual public Ca
{
    ~Cd(void)
    {
          cout << "~Cd" << endl;
            
    }

};
struct Ce {
    ~Ce(void)
    {
          cout << "~Ce" << endl;
            
    }

};
struct Cf :virtual public Ca 
{
    ~Cf(void)
    {
          cout << "~Cf" << endl;
            
    }

};
struct Cg :public Ca,public Cb
{
    ~Cg(void)
    {
          cout << "~Cg" << endl;
            
    }

};
struct Ch
{
    ~Ch(void)
    {
          cout << "~Ch" << endl;
            
    }

};

struct Ci {
    ~Ci(void)
    {
          cout << "~Ci" << endl;
            
    }

};
struct Ck :public Cc,public Cd,public Ce,public Cf ,public Cg
{
    Ch h;
      Ci i;
        ~Ck(void)
        {
              cout << "~Ck" << endl;
                
        }

};

int main()
{
    Ck obj;
    return 0;

}
