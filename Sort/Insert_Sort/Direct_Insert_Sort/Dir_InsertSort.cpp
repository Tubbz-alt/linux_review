#include<iostream>
#include<time.h>
using namespace std;

void Dir_Insert_Sort(int arr[],int length)
{
  for(int i = 2;i <= length;++i)
  {
    int j = i-1;
    arr[0] = arr[i];
    while(arr[0] < arr[j])
    {
      arr[j+1] = arr[j];
      j--;
    }
  arr[j+1] = arr[0];
  }
}

int main()
{
  int arr[11];
  for(int i = 0;i < 11;i++)
  {
    arr[i] = rand() % 10;
  }
  for(auto &e : arr)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  Dir_Insert_Sort(arr,11);
  for(auto &e : arr)
  {
    cout<<e<<" ";
  }
  cout<<endl;
  return 0;
}
