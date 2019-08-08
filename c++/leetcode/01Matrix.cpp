#include<bits/stdc++.h>

using namespace std;

/*
 * 题目大意：给定一个01矩阵，让你找到每一个1对应的最近的0的距离，距离=abs(x1-x2)+abs(y1-y2)
 * 思路：完全没思路，想着暴力，先把那些为0的位置记录下来，然后把1的我位置记下来，暴力查找一下0的所有的位置
 * 看了网上的题解，居然你是用 bfs去更新，每个点的最小的距离，这真是很奇怪，bfs的这个空复杂度很高啊，
 * 不过对于为0的点，那么就只搜一遍，为1的点可能搜好几遍。
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int max_int = 0x3f3f3f;
        int n = matrix.size();
        int m = matrix[0].size();
        int xx[] = {0,-1,0,1};
        int yy[] = {-1,0,1,0};
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j] == 1){
                   matrix[i][j] = max_int; 
                }else{
                    q.push({i,j});
                }
            }
        }
         while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (int i=0;i<4;++i) {
                int x = t.first + xx[i], y = t.second + yy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= matrix[t.first][t.second] + 1) continue;
                matrix[x][y] = matrix[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return matrix;
    }
};

int main(){
	return 0;
}
