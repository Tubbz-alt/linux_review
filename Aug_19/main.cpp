#include"fish.h"
#include"bird.h"

int main()
{
  string name1, name2;
  cin >> name1 >> name2;

  Animal *myBird = new Bird(name1), *myFish = new Fish(name2);

  myBird->action();
  myFish->action();

  delete myBird;
  delete myFish;



  return 0;
}
