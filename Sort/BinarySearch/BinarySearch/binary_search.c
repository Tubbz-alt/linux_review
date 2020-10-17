#include<stdio.h>

int Binary_Search(int *arr,size_t k,int left,int right)
{
 int mid = left + (right - left) / 2;
  while (left <= right)
  {
    if (arr[mid] > k)
    {
      right = mid - 1;

    }
    else if (arr[mid] < k)
    {
      left = mid + 1;

    }
    else  if(arr[mid] == k)
    {
      return mid;

    }

  } 
  return -1;

}


int main()
{
  int arr[] = {1,2,4,5,5,6,6};
  size_t length = sizeof(arr)/sizeof(arr[0]);
 int res =  Binary_Search(arr,1,0,length-1);
  printf("%d",res);
  return 0;
}

