/*
 * 题目意思：给定一个序列，让你找到满足条件的最长的序列的元素个数，条件为
 *   A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i]
 * 
 * 思路： 对每一个位置i记录其前面的所有的位置到该位置的差值的所有的满足条件元素的个数，地推方程为
 * tmp[{i,cha}] = max(tmp[{i,cha}],v[j][{j,cha}]+1);
 * 用来更新与当前位置差值为cha的元素个数
 *
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<map<pair<int,int>,int>>v(n);
        int ans = 0;
        if(n == 0 || n == 1){
            return n;
        }
        for(int i=0;i<n;++i){
            map<pair<int,int>,int>tmp;
            for(int j=0;j<i;++j){
                int cha = A[i]-A[j];
                if(v[j].find({j,cha}) == v[j].end()){
                    v[j][{j,cha}] = 0;
                }
                tmp[{i,cha}] = max(tmp[{i,cha}],v[j][{j,cha}]+1);
                ans = max(ans,tmp[{i,cha}]);
            }
            v[i] = tmp;
        }
        return ans+1;
    }
};
