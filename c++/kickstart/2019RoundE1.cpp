#include <bits/stdc++.h>
/**
 * 题目大意，给定n个糖，用红线和黑线串起来，其中红线甜度为2，黑线甜度为1，问你最少的甜度
 * 思路：保留的所有的黑线，如果没有连的糖就用红线，
 * 很简单，并查集就可以了，并查集统计所有的黑线糖果，
 * 最后加上所有的没在该集合内的糖果红线串起来即可
 */
using namespace std;

int n, t, m, a, b;
vector<int> fa(1e5 + 10);
int found(int x) { return x == fa[x] ? x : fa[x] = found(fa[x]); }
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
      fa[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      int x = found(a);
      int y = found(b);
      if (x != y) {
        fa[x] = y;
        ans++;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == fa[i]) {
        ans += 2;
      }
    }
    cout << "Case #" << cas << ": " << ans - 2 << endl;
  }
  return 0;
}

