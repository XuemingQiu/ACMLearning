#include<bits/stdc++.h>

using namespace std;

/**
 *
 * 题目大意：给定一个01矩阵，1代表障碍物，问你最多修改K次，能从左上到达右下的的最短路径
 * 思路：深搜是不可以的，因为会爆栈，自己在比赛时是这么写的，但是没有过。
 * 正确思路： bfs，对于每一个点，上下左右四个方向，然后通过判断该位置处的K值是不是比之前访问的时候大，如果是的话。那就进入队列，就是一层层的访问，很多巧妙的思路
 * 其实说实话，这题也为很裸的BFS，奈何自己想不出来啊，捉急！！
 * */
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n =  grid.size(),m = grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,-1));
        vector<int>dir = {0,-1,0,1,0};
        queue<vector<int>>q;
        int step = 0;
        q.push({0,0,k});
        visit[0][0] = k;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto t = q.front();
                q.pop();
                if(t[0]==n-1&&t[1]==m-1)return step;
                for(int i = 0;i <4;++i){
                    int x1 = t[0]+dir[i];
                    int y1 = t[1]+dir[i+1];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m){
                        int nk = t[2]-grid[x1][y1];
                        if(nk > visit[x1][y1] && nk >= 0){
                            q.push({x1,y1,nk});
                            visit[x1][y1] = nk;
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
