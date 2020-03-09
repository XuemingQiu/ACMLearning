# include <bits/c++.h>


using namespace std;

/**
 *
 * 题目大意：求manager通知所有员工所需要的最短时间。
 * 思路：bfs求解出最长的路径即可。
 * 两个多月没做题了。。。。。。。。。。。。。。。。。
 * 基本也不会了。。。。。。。。。。。。。。。。
 *
 */


class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>>edge;
        
        int ans = 0;
        for(int i=0;i<manager.size();++i){
            int fa = manager[i];
            if(fa == -1)continue;
            edge[fa].push_back(i);
        }
    
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int si = q.size();
            int mx = 0;
            while(si--){
                pair<int,int> p = q.front();
                q.pop();
                for(auto t:edge[p.first]){
                    int cost = p.second+informTime[p.first];
                    ans = max(ans,cost);
                    q.push({t,cost});
                }
            }
        }
        return ans;
    }
};


int main(){
    return 0;
}
