#include<bits/stdc++.h>

using namespace std;
/*
 * 题目意思：给定一对有序的区间，和一个未插入的区间，让你插入该区间到那一堆区间，合并，保持那一堆区间有序
 * 思路：二分，每一个区间有两个数，把他们从小到达排列在一个数组中，利用c++的upper_bound去查找那个要插入区间的端点值应该插在哪两个值之间，然后/2得到所在的区间，合并他们即可。
 * 一些坑点：
 *     1. 如果要插入区间本来就大于那一堆最大的区间，那么就直接插在最后
 *     2. 如果要插入的区间比那一堆的最小的区间的话，插在第一个的位置
 *     3. 如果找的区间的右端点小于了要插入的左端点，那么先插入原来的区间，在合并右端点即可。
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int>tmp;
        int n = intervals.size();
        if(n == 0 || intervals[n-1][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[0][0] > newInterval[1]){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        for(int i = 0;i < n;++i){
            tmp.push_back(intervals[i][0]);
            tmp.push_back(intervals[i][1]);
        }
        int index1 = (upper_bound(tmp.begin(),tmp.end(),newInterval[0])-tmp.begin())-1;
        int index2 = (upper_bound(tmp.begin(),tmp.end(),newInterval[1])-tmp.begin())-1;
        index1 /= 2;
        index2 /= 2;
        vector<vector<int>>ans;
        for(int i=0;i<n;){
            if(index1 == i){
                if(newInterval[0] > intervals[i][1]){
                    ans.push_back(intervals[i]);
                    ans.push_back({newInterval[0],max(newInterval[1],intervals[index2][1])});
                }else{
                    ans.push_back({min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[index2][1])});
                }
                i = index2+1;
            }else{
                ans.push_back(intervals[i]);
                i += 1;
            }
        }
        return ans;
    }
};

int main(){
   return 0;
}
