#include<iostream>

using namespace std;

void PrintArray(int Array[],int left,int right)
{
  for(int i = left; left <= right;left++)
  {
    cout<<Array[left]<<" ";
  }
}
void Swap(int arr[],int &left,int &right)
{
 int temp = left;
 left = right;
 right = left; 
}
void Permutation(int Array[],int p, int q)
{
  if(p == q)
  {
    PrintArray(Array,0,q);
  }
  for(int i = p;i <= q;++i)
  {
    Swap(Array,p,q);
    Permutation(Array,p+1,q);
    Swap(Array,p,q);
  }
}
int main()
{
  int arr[] = {1,2,3};
  Permutation(arr,0,2);
  return 0;
}
