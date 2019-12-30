#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意：给定两个字符串，找到包含这两个字符串序列的最短的字符串
 * 区别：最长子序列和字符串查找的区别，前者使用的是最长公共子序列LCS算法，典型的动归算法，后者的是KMP算法了
 * 思路：直观上就是说找到最长的子序列，然后见缝插针那些在两个单词里面的字母，最长子序列我们使用dp来算，没问题
 * 然后见缝插针的，我们要倒着来计算插入，具体见代码
 * 思路很巧妙的
 */


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
		// 典型的LCS算法
        for(int i=1;i<=l1;++i){
            for(int j=1;j<=l2;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        // cout << dp[l1][l2] << endl;
        string ans = "";
		// 倒着插入连个字符串中的字母，相同话就插一个，从右下向左和上开始处理
        while(l1||l2){
            if(l1 == 0){ ans += str2[--l2];}
            else if(l2==0){ans += str1[--l1];}
            else if(str1[l1-1]==str2[l2-1]){ans += str1[--l1];--l2;}
            else if(dp[l1-1][l2] == dp[l1][l2]){ans += str1[--l1];}
            else if(dp[l1][l2-1] == dp[l1][l2]){ans += str2[--l2];}
        }
        int i=0,j=ans.size()-1;
        // cout << ans << endl;
        while(i<j){
            swap(ans[i++],ans[j--]);
        }
        return ans;
    }
};

int main(){
	return 0;
}
