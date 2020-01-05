#include<bits/stdc++.h>

using namespace std;

/**
 * 题目：给定每个人的朋友，和每个人喜欢看的看的视频，问给定一个id，到第level个的视频有哪些，第0个level就是自己，第一个level就是自己的朋友，第2个level是自己的朋友的朋友
 * 思路：很显然bfs，层序，找到level那一层，统计一下每个视频的次数
 * NOTE: 先按照频率，再按照字典序排序输出，
 *
 */

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int>q;
        q.push(id);
        vector<bool>used(friends.size(),false);
        used[id] = true;
        while(!q.empty()){
            if(level == 0){
               break;
            }
            int len = q.size();
            while(len--){
                id = q.front();
                q.pop();
                // cout << id << endl;
                for(auto t:friends[id]){
                    if(!used[t]){
                        used[t] = true;
                        q.push(t);
                    }
                }
            }
            level--;
        }
        map<string,int>mp; // 统计频率，map 默认字典许排序
        // cout << q.size() << endl;
        // cout << " *** " << endl;
        while(!q.empty()){
            id = q.front();
            // cout << id << endl;
            q.pop();
            for(auto t:watchedVideos[id]){
                if(mp.find(t) == mp.end()){
                    mp[t] = 1;
                }
                mp[t]+=1;
            }
        }
        vector<string>ans;
        while(mp.size() != 0){
            int mi = 0x3f3f3f3f;
            string key = "";
            for(auto t:mp){
                if(t.second < mi){
                    mi = t.second;
                    key = t.first;
                }
            }
            ans.push_back(key);
            mp.erase(key);
        }
        return ans;
    }
};

int main(){
	return 0;
}
