#include <bits/stdc++.h>
/*
 * 题目大意：给定一数组的数，找到其全排列，不能有重复
 * 思路：深搜即可.set去一下重就ok了
 *
 */
using namespace std;

class Solution {
public:
    void dfs(int index,vector<int>& nums,set<vector<int>>& ans,vector<int>&tmp,vector<bool>used){
        if(index==nums.size()){
            ans.insert(tmp);
            return;
        }
        for(int i =0;i<nums.size();++i){
            if(!used[i]){
                used[i] = true;
                tmp[index] = nums[i];
                dfs(index+1,nums,ans,tmp,used);
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        vector<int>tmp(nums.size());
        dfs(0,nums,ans,tmp,used);
        vector<vector<int>>ans2;
        for(auto t:ans){
            ans2.push_back(t);
        }

        return ans2;
    }
};

int main(){
	return 0;
}
