#include<bits/stdc++.h>

using namespace std;

/*
 * 题目大意：给你一个图graph，graph[i]表示和节点i连接的边，让你求该图能不能构成二分图
 * 思路：二分图匹配算法，染色问题，分为深搜和广搜的写法https://blog.csdn.net/qiuxueming_csdn/article/details/70969166，每次从未染色的点开始进行，和它相连的顶点染成相反的颜色。
 *
 */

class Solution {
public:
    bool judge(vector<vector<int>>& graph,int color,int cur, vector<int>& colors){
        if(colors[cur] != 0) return colors[cur]==color;
        colors[cur] = color;
        for(int i:graph[cur]){
            if(!judge(graph,-1*color,i,colors)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size());
        for(int i = 0;i <graph.size();++i){
            if(colors[i] == 0 && !judge(graph,1,i,colors)){
                return false;
            }
        }
        return true;
    }
};

int main(){
	return 0;
}
