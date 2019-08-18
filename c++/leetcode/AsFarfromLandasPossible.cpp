#include <bits/stdc++.h>

using namespace std;

/**
 * 題目大意：給定一個由０，１构成的矩阵，在全局上的０距离１的最远的距离，每个０的距离为其周围１的最近的距离，距离=abs(x1-x2)+abs(y1-y2)
 * 思路：和542 01 matrix 很像，利用bfs每层开始搜索即可。最后得到一个全局的最大值。
 */
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;++i){
            for(int j = 0;j <m;++j){
                if(grid[i][j]==1){
                   q.push({i,j});
                }
            }
        }
        if(q.size()==0||q.size()==n*m) return -1;
        int ans = -1;
        int xx[] = {-1,0,0,1};
        int yy[] = {0,-1,1,0};

        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto t = q.front();
                q.pop();
                for(int i = 0;i < 4;++i){
                int x1 = t.first+xx[i];
                int y1 = t.second+yy[i];
                    if(x1>=0&&x1<n&&y1>=0&&y1<m && grid[x1][y1]==0){
                        q.push({x1,y1});
                        grid[x1][y1] = 1;
                    }
                }
            }
            ans += 1;

        }
        return ans==0?-1:ans;
    }
};

int main(){
	return 0;
}
