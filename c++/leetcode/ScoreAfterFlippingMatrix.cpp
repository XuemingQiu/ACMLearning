#include<bits/stdc++.h>

using namespace std;

/**
 * 题目大意：给顶一个二维数组，每次选定一行或者一列进行变化，0变成1,1变成0，，可以操作无限次，每行代表一个二进制的数，问你最后构成的最大和。
 * 思路：最容易想到暴力，每行每列都有2种变化，但是非常不好写
 * 根据2进制的概念，首位一定大于其余各位之和，那么我们一定保证首位是1，即行遍，然后从第二列开始，每列的1的个数最多即可，选择列变
 *
 */

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for(int i = 0;i < m;++i){ //首位
            if(A[i][0] == 0){
                for(int j = 0;j<n;++j){
                    A[i][j] = A[i][j]==0?1:0;
                }
            }
        }
        for(int j=1;j<n;++j){ //从第2列开始，每列保证1最多
            int cnt = 0;
            for(int i=0;i<m;i++){
                if(A[i][j]==1){
                    cnt++;
                }
            }
            if(cnt < m-cnt){
                for(int i=0;i<m;i++){
                    A[i][j] = A[i][j]==0?1:0;
                }
            }
        }
        int ans = 0;
        for(int i =0;i < m;++i){
            int tmp = 0;
            for(int j=0;j<n;++j){
                tmp = tmp*2+A[i][j];
            }
            ans += tmp;
        }
        return ans;
    }
};

int main(){
	return 0;
}
