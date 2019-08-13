#include<bits/stdc++.h>

/*
 * 题目大意：一群孩子站成一排，每个孩子有一个Ratings(身高)吧，身高越高，分到的糖果也要比周围的人多
 * 思路：双向扫描各一次，如果前向扫描，如果身高越高，则在前面的一个基础的糖+1，
 * 后向扫描的时候同样更新，每个取最大的值就可以了
 * 具体写法看代码
 * 很简单的题目，为何是hard难度
 */
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int>v(n);
        for(int i=0;i<n;++i){
            v[i] = 1;
        }
        for(int i = 1;i<n;++i){
            if(ratings[i]>ratings[i-1]){
                v[i] = v[i-1]+1;
            }
        }
        for(int i = n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                v[i] = max(v[i],v[i+1]+1);
            }
        }
        for(int i=0;i<n;++i){
            ans += v[i];
        }
        return ans;
    }
};

int main(){
    return 0;
}
