#include<iostream>
#include<map>
#include<set>
#include<string>
#include<functional>
using namespace std;

/*
template<class Type>
class myStruct
{
  typedef Type value_type;
  typedef Type* pointer;
  typedef Type& reference;
  typedef const Type& const_reference;
};
  



int main()
{
  pair<string,string> p1("str1","Hello p1");
 // p1.insert("str1","Hello p1");
 // 在set中value的元素值是不允许被修改的，但是可以将其删除掉
 multiset<int,greater<int>> sq = {1213,121,12,126,67,78,87,87,98};
  sq.erase(1213);
  sq.insert(1);
 for(auto &e : sq)
 {
   cout<<e<<" ";
 }
cout<<"sq.size()"<<sq.size()<<endl;
 return 0;
}*/

// map是关联式容器  键值和实值绑定在一起的 
//键值不允许修改，但是对于实值进行修改   如果访问某个不存在的关键值，会对这个关键值进行插入数据（对关键值有序的情况进行判断） 
//底层会对键值进行排序

// at 会检查有效性 但是【】不但不会对有效值进行检查，还会对越界数据进行构造插入
/*int main()
{
  map<int ,string> ismap;
  pair<int ,string> v[] = {{1,"student"},{2,"size"},{3,"I dont know"}};
  int n = sizeof(v) / sizeof(v[0]);

  cout<<"n = "<<n <<endl;
// cout<<ismap.at(2)<<endl;
  for(int i = 0; i< n;++i)
  {
    ismap.insert(v[i]);
  }
 cout<<ismap.at(2)<<endl;
  for(const auto &e : ismap)
  {
    cout<<e.first<<" "<<e.second<<endl;
  }
  return 0;
}
*/


int main()
{
  map<int ,string> ismap =  {{1,"student"},{2,"size"},{3,"I dont know"}};
  int n = sizeof(ismap) / sizeof(ismap[0]);

  cout<<"n = "<<n <<endl;
// cout<<ismap.at(2)<<endl;
  ismap.insert(ismap.begin(),make_pair(8,"test1"));
  ismap.insert(ismap.end(),make_pair(12,"test2"));
  for(const auto &e : ismap)
  {
    cout<<e.first<<" "<<e.second<<endl;
  }
  return 0;
}











