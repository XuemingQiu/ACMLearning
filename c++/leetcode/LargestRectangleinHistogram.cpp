#include<bits/stdc++/.h>

using namespace std;


/**
 * 题目大意，给定直方图，让求最大的矩形面积
 * 思路：有点像水桶的题目，最小O(n^2)复杂度，该题目为hard题，显然会超时
 * 看了网上的思路，使用递增栈，主要是每次当前的heights[i]比栈顶元素小得时候，就把栈里面大于该值的元素更新成当前的高度，，具体看代码
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int len = heights.size();
        int area = 0;
        for(int i=0;i<len;++i){
            if(s.empty() || heights[i] >= s.top()){
                s.push(heights[i]);
            }else{
                int cnt = 0;
                while(!s.empty() && heights[i]<s.top()){ // 弹出小于当前值的栈里面的元素
                    cnt++;
                    area = max(area,cnt*s.top());
                    s.pop();
                }
                while(cnt--){ // 弹出多少个，填入多少个
                    s.push(heights[i]);
                }
                s.push(heights[i]);
            }
        }
        int cnt = 0;
        while(!s.empty()){
            cnt++;
            area = max(area,cnt*s.top());
            s.pop();
        }
        return area;
    }
};

int main(){
	return 0;
}
