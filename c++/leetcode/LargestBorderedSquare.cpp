#include<bits/stdc++.h>
/*
 * 题目大意：给定一个由0和1构成的矩阵，然后让你找到所有的边均为1的最大的正方形面积 
 * 思路： 第一次以为暴力直接判断，但应该会超时，毕竟时间复杂度到O(n^4)了，然后巧妙的处理一下，先预存每一行的每个位置的最长的1的连续个数row[i][j]
 * 然后遍历列，统计每一列的连续最长的1的个数b，然后对每个位置判断其能够成的最大的正方形的边长t=min(row[i][j],b),
 * 然后欧判断(i-t,j-t)到(i,j)，t->sqrt(ans)到t，是不是构成的合理的正方形
 *
 */

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>>row;
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;++i){
            vector<int>tmp;
            int rs = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    rs = 0;
                    tmp.push_back(rs);
                    continue;
                }
                rs += 1;
                tmp.push_back(rs);
            }
            row.push_back(tmp);
        }
        // cout << row[5][5] << " " << row[6][5] << endl;
        // cout << row[7][5] << " " << row[8][5] << endl;
        
        for(int j=0;j<m;++j){
            int rs = 0;
            // cout << endl;
             for(int i = 0;i<n;++i){
                if(grid[i][j] == 0){
                    rs = 0;
                    continue;
                }
                rs += 1;
                int t = min(row[i][j],rs);
                 for(int step = t;step>sqrt(ans);--step){
                    int x = i-step+1;
                    int y = j-step+1;
                    bool flag = 0;
                    for(int u = y;u<=j;++u){
                        if(grid[x][u] == 0){
                            flag = 1;
                        }
                    }
                     for(int u = x;u<=i;++u){
                         if(grid[u][y] == 0){
                             flag = 1;
                         }
                     }
                     for(int u=y;u<=j;++u){
                         if(grid[i][u] == 0){
                             flag = 1;
                         }
                     }
                     for(int u = x;u<=i;++u){
                         if(grid[u][j] == 0){
                             flag = 1;
                         }
                     }
                    if(!flag){
                        ans = max(ans,step*step);
                        // cout << i << " " << j << " " << step << endl;
                    }
                }
             }
        }
       return ans;
    }
};
