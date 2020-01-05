#include <bits/stdc++.h>
 
using namespace std;

/***
 * 题目大意： 很有意思的题目，如果满足 i <j && a[i]<a[j]那么这样的序列，是合格的，
 * 给定一串序列 s1,s2,.....sn,   sx+sy拼接成新的序列，问有多少对这样的（x，y）是合格的
 * 思路：对于本身合格的，那么它和任意的组合都是合格的，比如s1合格，那个不论s2合不合格（s1,s2）(s2,s1)都合格
 * 对于本身，记录每个si的最大最小的值，然后只需要比较 当前序列的最小值，有多少比这个最小值大的序列的最大值的个数
 * 特点，别说最后直接一个暴力，要按最大值排序，二分查找
 * 时间复杂度 O(nlogn)
 *
 */



struct point {
    int mi;
    int mx;
    bool operator<(const point& a) {
        if (a.mx == mx) {
            return a.mi > mi;
        }
        return a.mx > mx;
    }
};

vector<point> mp;
vector<int> mii;
vector<int> mxx;

int main() {
    int n, li, a;
    long long ans = 0;
    cin >> n;
 
    long long d = 0;
    for (int i = 0; i < n; i++) {
        cin >> li;
        cin >> a;
        int mi = a, mx = a;
        bool used = false;
        while (--li) {
            cin >> a;
            if (mi < a) {
                used = true;
            }
            mi = min(mi, a);
            mx = max(mx, a);
        }
        if (used) {  // 本身合格
            d++;
            ans += n * 2 - 1;
        } else {
            point p;
            p.mi = mi;
            p.mx = mx;
            mp.push_back(p);
        }
    }
    ans -= d * (d - 1); // 去掉多算的一些，比如在s1合格，s2也合格，那么在计算的时候会由s1得到(s1,s2)(s2,s1)，s2也得到(s2,s1),(s1,s2)，这就多算了一遍   ，一直卡在这里，我始终以为我的公式对的，早上才发现 
    sort(mp.begin(), mp.end());
 
    for (auto t : mp) {
        mii.push_back(t.mi);
        mxx.push_back(t.mx);
    }
    for (auto t : mii) {
        int index = upper_bound(mxx.begin(), mxx.end(), t) - mxx.begin(); // 二分查找，比我当前最小值大的 最大值的序列，
        if (index == mxx.size()) continue;
        ans += mxx.size() - index;
    }
    cout << ans << endl;
    return 0;
}
