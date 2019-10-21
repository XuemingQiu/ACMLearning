#include <bits/stdc++.h>


using namespace std;
/*
 * 题目大意：给你一个数组，你有一个操作，删去一个数，可以获得nums[i]点分数，惩罚是你要删掉数组中nums[i]+1和nums[i-1]的值，问你最后能达到的最大的值
 * 思路：第一遍没看数据量，敲了个乱七八糟的深搜，然后wa，超时，后来其实已经意识到的dp了，每个数据有两个操作，要么删，要么不删最后地推公式为：
 * dp[i][0] = max(dp[i-1][0],dp[i-1][1]);  0代表不要该数据
 * dp[i][1] = dp[i-1][0]+v[i].first*v[i].second; 这里nums[i-1]+1的值和nums[i]的值相同
 * 否则：
 * dp[i][1] = max(dp[i-1][0],dp[i-1][1])+v[i].first*v[i].second;
 *
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        nums.push_back(-1);
        vector<pair<int,int>>v;
        int cnt = 0,i = 0;
        for(i=0;i<nums.size()-1;++i){
            cnt += 1;
            if(nums[i] != nums[i+1]){
                v.push_back({nums[i],cnt});
                cnt = 0;
            }
        }
        vector<vector<int>>dp;
        for(int i=0;i<v.size();++i){
            vector<int>tmp(2,0);
            dp.push_back(tmp);
        }
        dp[0][0] = 0;
        dp[0][1] = v[0].first*v[0].second;
        ans = dp[0][1];
        for(int i = 1;i < v.size();++i){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            if(v[i].first == v[i-1].first+1){
                dp[i][1] = dp[i-1][0]+v[i].first*v[i].second;
            }else{
                dp[i][1] = max(dp[i-1][0],dp[i-1][1])+v[i].first*v[i].second;
            }
            ans = max(dp[i][0],dp[i][1]);
        }
        return ans;
    }
};


int main(){
	return 0;
}
