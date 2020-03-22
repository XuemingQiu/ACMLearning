#include <bits/stdc++.h>

using namespace std;

/*
 * 题目大意：给定n堆盘子（必须先取第一个再取第二个），每堆盘子有k个，每个盘子有一个值来描述其漂亮的程度，现在某人要取p个盘子，问你最大的漂亮程度？
 * 思路：取到第一堆的第i个的话，那么他之前的必须都取掉，对于小数据集使用深搜（每堆有0-k个取法）可以解决，但是大数据及不可以，所以考虑dp；
 * 其实有个模糊的0,1背包的意思，就是第i堆取第j个的时候，必须压入前j-1个，那么得到的漂亮的总数为 这j个之和；
 * 显然：dp[i][cost] = dp[i-1][cost-j]+stk[i][j]
 * 也就是取第i堆第j个，背包为cost时，就要从前一堆i-1里面的[cost-j]变化才可以达到当前堆的背包大小的最大价值
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios ::sync_with_stdio(0);
    int t;
    int n, k, p;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n >> k >> p;
        vector<vector<int>> stk(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                cin >> stk[i][j];
                stk[i][j] += stk[i][j - 1];
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n*k+1));
        for(int i=1;i<=n;++i){
            for(int j=0;j<=k;++j){
                for(int cost=p;cost>=j;--cost){
                    dp[i][cost] = max(dp[i][cost],dp[i-1][cost-j]+stk[i][j]);
                }
            }
        }
        cout << "Case #" << cas << ": " << dp[n][p] << endl;
    }
    return 0;
}

