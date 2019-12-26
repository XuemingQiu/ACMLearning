#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意：给定一个数组，让你求所有的不重复的子集
 * 思路：经典的深搜题目，寻找子集问题
 */
class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<int>& nums,vector<int>&used,vector<int>tmp,int index){
        for(int i=index;i<nums.size();++i){
            if(!used[i]){
                tmp.push_back(nums[i]);
                used[i] = 1;
                if(find(ans.begin(),ans.end(),tmp) == ans.end()){
                    ans.push_back(tmp);
                    dfs(ans,nums,used,tmp,i);
                }
                used[i] = 0;
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};
        vector<int>used(nums.size()+1,0);
        vector<int>tmp;
        // ans.push_back(tmp);
        for(int i =0;i<nums.size();++i){
            dfs(ans,nums,used,tmp,i);
            tmp.clear();
            used.clear();
        }
        
        return ans;
    }
};
int main(){
	return 0;
}
