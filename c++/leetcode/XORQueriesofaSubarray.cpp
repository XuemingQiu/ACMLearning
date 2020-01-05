#include<bits/stdc++.h>

using namespace std;

/**
 *  题目大意。给定一串数字，问给定区间上的异或值
 *  思路：根据 a xor b  = c 那么 a = c xor b, b = c xor a,
 *  记录每个位置到最开始的异或值，然后区间端点 异或值相减
 *
 */

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans,tmp;
        int index=0;
        for(int i=0;i<arr.size();++i){
            index = (index^arr[i]);
            tmp.push_back(index);
        }
        for(auto t:queries){
            int s = t[0];
            int tar = t[1];
            if(s==0){
                ans.push_back(tmp[tar]);
            }else{
                ans.push_back(tmp[tar]^tmp[s-1]);
            }
        }
        return ans;
    }
};

int main(){
	return 0;
}
