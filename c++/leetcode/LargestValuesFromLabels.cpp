#include<bits/stdc++.h>

using namespace std;

/*
 * 题目大意：给你一个数组，每个值对应一个lable,让你最多选num_wanted个，每个lable最多用use_limit的次，问你选出的数组之和最大是多少。
 * 思路：自己给数组和lable对应，按照大小排序，直接从大到小选数字即可。这样一定保证找到的数据纸盒最大。
 *
 */
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int,int>>v;
        map<int,int>mp;
        for(int i=0;i<values.size();++i){
            v.push_back({values[i],labels[i]});
            mp[labels[i]] = 0;
        }
        sort(v.begin(),v.end());
        int ans = 0;

        for(int i = v.size()-1;i>=0;--i){
            int val = v[i].first;
            int lab = v[i].second;
            if(num_wanted>0&&mp[lab] < use_limit){
                ans += val;
                num_wanted--;
                mp[lab]++;
            }
        }
        return ans;
    }
};

int main(){
	return 0;
}
