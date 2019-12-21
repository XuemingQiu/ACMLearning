#include<bits/stdc++.h>

using namespace std;

/*
 * 题目大意：给定两种类型的汤各N毫升，有四种操作,问你A先为空 + AB同时为空的概率
 * 思路，深搜，直接按照题目计算机即可，为啥，我写bfs居然错了，也是震惊
 *
 */

class Solution {
public:
    double dfs(int a, int b,map<int,map<int,double>>&dp){
        if (a <= 0 && b > 0) {
            return 1;
        }
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (b <= 0) {
            return 0;
        }
        if(dp[a][b]) return dp[a][b];
        dp[a][b] = 0.25*(dfs(a-100,b,dp)+dfs(a-75,b-25,dp)+dfs(a-50,b-50,dp)+dfs(a-25,b-75,dp));
        return dp[a][b];
    }
    double soupServings(int N) {
        if(N>=5000) return 1;
        map<int,map<int,double>>dp;
        return dfs(N,N,dp);
    }
};


int main(){
	return 0;
}
