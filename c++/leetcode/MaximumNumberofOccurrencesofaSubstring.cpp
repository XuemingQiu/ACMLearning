#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意：给定一个字符串，问你长度限制在[minSize,maxSize]之间的包含不同字母数不超过的maxLetters的子串出现的最多的次数是多少。
 * 思路： 暴力，枚举 + 记录
 */

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<vector<int>>v(s.size(),vector<int>(26,0)); // 用来记录每个位置的26个字母的每个字母的数量
        v[0][s[0]-'a'] = 1;
        for(int i=1;i < s.size();++i){
            v[i] = v[i-1];
            v[i][s[i]-'a'] = v[i-1][s[i]-'a']+1;
        }
        unordered_map<string,int> occr;

        for(int k = minSize;k<=maxSize;++k){
            for(int j = 0;j <= s.size()-k;++j){
                int ll = 0;
                if(j == 0){
                    for(int i = 0;i < 26;++i){
                        ll += (v[j+k-1][i]) ==0 ? 0:1;
                    }
                }else{
                    for(int i = 0;i < 26;++i){
                        ll += (v[j+k-1][i]-v[j-1][i]) ==0 ? 0:1;
                    }
                }
                // cout << ll << endl;
                if(ll <= maxLetters){
                    string ss = s.substr(j,k);
                    // cout << j <<" "<<  ss << endl;
                    occr[ss]++; //将该字符串放在map里面，第一次做的时候，一顿模拟
                }
            }
        }
        int ans = 0;
        for(auto t : occr){
            // cout << t.first << endl;
            ans = max(ans,t.second);
        }
        return ans;
    }
};

int main(){
	return 0;
}
