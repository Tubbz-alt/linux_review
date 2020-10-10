#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Swap(int *num1,int *num2)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
void Bubble_Sort1(int *arr,int length)
{
   for(int i = 0;i < length;++i)
   {
      for(int j = 0; j < length - i - 1; ++j)
      {
        if(arr[j] > arr[j+1])
        {
          Swap(&arr[j],&arr[j+1]);
        }
      }
   }
}

//优化1 针对完全有序数组进行优化

void Bubble_Sort2(int *arr,int length)
{
   bool flag = 1;
   for(int i = 0;i < length;++i)
   {
      for(int j = 0; j < length - i - 1; ++j)
      {
        if(arr[j] > arr[j+1])
        {
          Swap(&arr[j],&arr[j+1]);
          flag = 0;
        }
      }
      if(!flag)
        break;
   }
}

//算法 ： 记录下最后一次交换的位置，适用于部分有序序列

// 这个的优化其实并不是很多，相当于只是记录了最后一次的交换位置然后该位置以后就是有序序列
void Bubble_Sort3(int *arr,int length)
{
  bool flag = 1;
  int k = length - 1;
  int pos;
   for(int i = 0;i < length;++i)
   {
      for(int j = 0; j < k; ++j)
      {
        if(arr[j] > arr[j+1])
        {
          Swap(&arr[j],&arr[j+1]);
          pos = j;
        }
      }
    if(flag)
      break;
    k = pos;
   }
}






int main()
{
  int arr[10];
  for(int i = 0 ;i < 10;++i)
  {
    arr[i] = rand()%100 + 1; 
  }
Bubble_Sort1(arr,10);

for(int j = 0; j < 10;++j)
{
  
  printf("%d ",arr[j]);
}


  return 0;
}
