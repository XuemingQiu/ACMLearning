#include <bits/stdc++.h>

using namespace std;
/****
 * 题目大意：给定n个房子和你的总钱数，问你能购买的最多的房子
 * 思路：像不像背包问题？哈哈哈，其实是贪心啊，背包其实思路也不错，但是会超时啊，所以只能是排序贪心了
 * 比较简单
 */


int main() {
    int t;
    ios ::sync_with_stdio(0);
    cin >> t;
    int n, b;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n >> b;
        vector<int> house(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> house[i];
        }
        sort(house.begin(), house.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (b >= house[i]) {
                ans++;
                b -= house[i];
            }
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

