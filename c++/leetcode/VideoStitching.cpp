#include<bits/stdc++.h>


using namespace std;

/**
 * 题目大意：给你一个[0,T]的比赛时间，问你给定的片段中最少需要几段可以构成该时间片
 * 思路：贪心，排序相同的开始时间，选取结束最晚的那一段，然后开始时间排序，一次选择，交叉的片段，最后一定是最少的。
 * 为了减少排序，利用map的自动排序的功能。
 */

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        map<int,int>mp;
        for(auto t:clips){
            mp[t[0]] = max(mp[t[0]],t[1]);
        }
        if(mp.size()==0) return 0;
        int ed  = mp.begin()->second;
        int front = ed;
        int ans = 1;
        if(mp.begin()->first != 0) return -1;
        for(map<int,int>::iterator t=mp.begin();t!=mp.end(); ++t){
            // if(t->second <= ed){continue;}
            if(t->first > ed){   // 得到当前已经比我上次的大了，也就是断层了
                ans++;
                ed = front;
            }
            if(t->first == ed){ // 正好连接上，那一定要选啊
                ed = t->second;
                ans++;
            }
            if(ed >= T) return ans;
            if(t->second >= T && t->first <= ed) return ans+1; // 这一行主要判断最后一个是不是满足
            front = t->second;
        }
        return  -1;
    }
};

int main(){
	return 0;
}
