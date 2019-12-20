#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意：给你一个字符串数组，让你在约束n个0，和m个1的约束下，找到最大的字符串个数，每个字符串允许用一遍
 * 思路：裸的01背包问题，不过这次是一个二维的包，不再是以为的包
 * 例子：
 *      Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 *      选出 “10,”0001”,”1”,”0” 一共有5个0,3个1
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>>jishu;
        for(int i=0;i<len;++i){
            int zeros=0;
            int ones=0;
            for(auto t : strs[i]){
                if(t=='0') zeros++;
                else ones++;
            }
            jishu.push_back({zeros,ones});
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 0;i < len;++i){
            for(int k = m; k >= jishu[i][0];--k){
                    for(int j=n;j >= jishu[i][1];--j){
                        dp[k][j] = max(dp[k][j],dp[k-jishu[i][0]][j-jishu[i][1]]+1);  //第一次没去减计数0 我也是服的我自己的
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
	return 0;
}
