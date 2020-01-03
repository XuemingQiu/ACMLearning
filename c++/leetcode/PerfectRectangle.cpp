#include<bits/stdc++.h>

using namespace std;

/**
 * 这是一道很有意思的题目，给你每个矩形的对角线顶点，让你判断这些小的矩形是不是构成大的矩形
 * 首先很朴素的想法就是，为找到 左下的顶点 ，和右上的顶点，判断面积是不是相同，重复的就肯定是不可以的false
 * 然后尝试了各种暴力的填充办法，但依旧是过不了
 * 然后看了网上的答案，很有意思，是对于每个小矩形的四个顶点如果重边，就是出现两次，也有可能4次，
 * 最后构成的大矩形只有四个顶点，所以就判断集合大小
 *
 */

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0;
        set<pair<int,int>>s;
        for(auto t: rectangles){
            area += (t[2]-t[0])*(t[3]-t[1]);

            pair<int,int>p1{t[0],t[1]};
            pair<int,int>p2{t[2],t[1]};
            pair<int,int>p3{t[2],t[3]};
            pair<int,int>p4{t[0],t[3]};
            for(auto t2 : {p1,p2,p3,p4}){
                if(s.find(t2) == s.end()){
                    s.insert(t2);
                }else{
                    s.erase(t2);
                }
            }
        }
        if(s.size()!=4) return false;
        int i = 0;
        pair<int,int>p1,p2;//这里为啥不用直接从记录个原始的左下坐标和右上的坐标呢 ，测试样例 [[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]] 完美的边界条件，
		                   //面积也符合，四个顶点，所以需要从集合里找到对角线的顶点
        for(auto t:s){
            if(i==0)p1=t;
            if(i==3)p2=t;
            i++;
        }
        return area==(p2.second-p1.second)*(p2.first-p1.first);
    }
};

int main(){
	return 0;
}
