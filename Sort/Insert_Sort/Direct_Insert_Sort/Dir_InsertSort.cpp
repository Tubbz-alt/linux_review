#include<iostream>
#include<time.h>
using namespace std;

void Dir_Insert_Sort(int arr[],int length)
{



}

int main()
{
  int arr[10];
  for(int i = 0;i < 10;i++)
  {
    arr[i] = rand() % 10;
  }
  Dir_Insert_Sort(arr,10);
  for(auto &e : arr)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  return 0;
}
