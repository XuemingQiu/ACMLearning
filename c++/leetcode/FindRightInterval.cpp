#include <bits/stdc++.h>

using namespace std;
/*
 * 题目意思：给定一对区间，让你找到每一个区间对应的最靠近的右区间，对应的下标。定义的右区间：对于区间(a,b),和(c,d),如果b<=c，则称(c,d)为(a,b)的右区间
 * 思路：暴力揭发会超时，时间复杂度为O(N^2),居然可以过大部分的数据，只有最后一个过不了
 * 可以用结构体+排序的方式做吧，然后利用好二分去查找得到下标，直觉是是这样，可是不好写啊。或许也是因为自己对c++不熟的缘故
 * 看了人家的解答，居然是用了ordermap来存一下，然后在lower_bound()查找。
 * 果然厉害，对c++的STL有了更深的认识。
 */
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>ans(n);
        map<int,int>m;
        for(int i=0;i<n;++i){
            m[intervals[i][0]] = i;
        }
        for(int i=0;i<n;++i){
            auto index = m.lower_bound(intervals[i][1]);
            if(index == m.end()){
                ans[i]  = -1;
            }else{
                ans[i] = index->second;
            }
        }
        return ans;
    }
};

