#include <bits/stdc++.h>

using namespace std;



/***
 * 题目大意：给定一堆网线，每根网线以连接的电脑关系形式给出，问这些网线能否链接所有的电脑
 * 思路：经典的并查集
 *
 */

class Solution {
public:
    int finds(int x,vector<int>&fa){
        return x==fa[x]?x:fa[x]=finds(fa[x],fa);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>fa(n,0);
        for(int i = 0;i < n;++i){
            fa[i] = i;
        }
        int len = connections.size();
        int cap = 0;
        for(int i = 0;i < len;++i){
            int a = connections[i][0];
            int b = connections[i][1];
            a = finds(a,fa);
            b = finds(b,fa);
            if(a==b){
                cap++;
            }else{
                fa[a] = b;
            }
        }
        int t = 0;
        // cout << cap << endl;
        for(int i=0;i<n;++i){
            // cout << fa[i] << endl; 
            if(fa[i] == i){
                t++;
            }
        }
        // cout << t << endl;
        if(cap >= (t-1)) return t-1;
        return -1;
    }
};

int main(){
	return 0;
}
