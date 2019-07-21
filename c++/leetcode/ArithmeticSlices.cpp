/**
 * 题目意思很简单，让你找到一个连续的序列，长度最少为3，是的连续的数字之间的差异相等，问你给定个一个数字串，满足这样的子序列有多少？
 * 思路：对于一个长度为n的满足的子序列，
 * 则会产生的合格子序列共有n(n-1)-(n(n+1)/2-1)个
 * 推到过程 长度为3的有n-2个
 *          长度为4的有n-3个
 *          ......
 *          长度为n的有n-n+1个
 *          对上述求和即可得到答案
 * 然后一次求得每个满足条件的子序列的长度即可。
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int k = 2;
        int ans = 0;
        for(int i = 2;i < n;++i){
            if(A[i]-A[i-1] == A[i-1]-A[i-2]){
                k++;
            }else{
                ans += k*(k-1)-(k*(k+1))/2+1;
                k = 2;
            }
        }
        // cout << k << endl;
        ans += k*(k-1)-(k*(k+1))/2+1;
        return ans;
    }
};

