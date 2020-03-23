#include <bits/stdc++.h>

using namespace std;
/***
 * 题目大意：给定n个数和k，问在不超过k次的添加数，是的两数之间的差异最小化；
 * 比如：
 * 3 1
 * 100 200 230
 * 结果是 100 150 200 230，所以差异是 50
 *
 * 思路：二分结果，得到在k限定下，最小的差异值
 * 
 *
 *
 */
int main() {
    ios ::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int l = 1, r = v[n - 1] + 5;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // cout << mid << endl;
            int cnt = 0;
            for (int i = 1; i < n; ++i) {
                cnt += (v[i] - v[i - 1]-1) / mid;   //  这里要减1
            }
            // cout <<  "cnt = " << cnt << endl;
            if (cnt <= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

/*
4
3 1
100 200 230
5 2
10 13 15 16 17
5 6
9 10 20 26 30
8 3
1 2 3 4 5 6 7 10
*/
