#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意： 给一个数组，问你，所有 数组元素是不是可以构成长度为K的连续的子数组
 * Input: nums = [1,2,3,3,4,4,5,6], k = 4
 * Output: true
 * Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
 * 思路： 模拟+map(排序)+, 设定开始值，然后逐渐减去后面的K个
 */

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0;i < nums.size();++i){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 0;
            }
            mp[nums[i]]++;
        }
        for(auto t : mp){
            // cout << t.first << " " << t.second << endl;
            if(t.second == 0) continue;
            int s  = t.first;
            while(mp[s] > 0){
                for(int i=0;i<k;++i){
                    // cout << s+i << endl;
                    if(mp.find(s+i) == mp.end()) return false;
                    mp[s+i]--;
                    if(mp[s+i] < 0) return false;
                }
            }
        }
        return true;
    }
};

int main(){
	return 0;
}
