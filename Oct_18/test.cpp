#include<iostream>
#include<vector>

using namespace std;
class Solution {
  public:
    void swap(vector<int>& arr, int l, int r) {
      int tmp = arr[l];
      arr[l] = arr[r];
      arr[r] = tmp;
    }
    void dfs(vector<int>& nums, int k, vector<vector<int>>& res) {
      if (k == nums.size() - 1) {
        res.push_back(nums);
      }
      for (int i = k; i < nums.size(); i++) {
        swap(nums, k, i);
        dfs(nums, k + 1, res);
        swap(nums, k, i);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      dfs(nums, 0, res);
      return res;
    }
};


int main()
{
  vector<vector<int>> res;
  vector<int> dp = {1,2,3};
  Solution a;
 res =  a.permute(dp);
  for(int i = 0;i < res.size();++i)
  {
    for(int j = 0;i < res[i].size();++j)
    {
      cout<<res[i][j]<<" ";
    }
    cout<<endl; 
  }

  return 0;
}
