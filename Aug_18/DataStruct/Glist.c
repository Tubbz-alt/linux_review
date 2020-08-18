#define ElenTag int 
#define AtomType int 
#include<stdio.h>

typedef struct GLNode
{
  ElenTag tag;
  union{
    AtomType atom;
    struct {
      struct GLNode *hp,*tp;
    }ptr;
  };
}*Glist;

int main()
{


  return 0;
}
