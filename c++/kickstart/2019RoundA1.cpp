#include<bits/stdc++.h>
/**
    题目：给你n个同学，每个同学有一个足球技能，让你挑选p个人组成一个球队,求组成该球队所需要的最小的时间来训练每个球员达到你选的所有的球员的最大技能值，每个技能值+1，需要花费1min
    思路：简单啊，排序后，统计连续p个人达到最大技能值需要花费的时间即可。
    坑点：int型最大值会超，改成long long AC.
*/
using namespace std;

int main() {
    int t,n,p;
    ios::sync_with_stdio(false);
    cin >> t;
    for(int cas=1; cas<=t; ++cas) {
        cin >> n >> p;
        vector<long long>v(n+1);
        v[0] = 0;
        for(int i=1; i<=n; i++) {
            cin >> v[i];
        }

        sort(v.begin(),v.end());
        for(int i=1; i<=n; ++i) {
            v[i] += v[i-1];
        }
        long long flag = 0x3f3f3f3f3f3f;
        for(int i = p; i <= n; ++i) {
            flag = min(flag,(v[i]-v[i-1])*p-(v[i]-v[i-p]));
        }
        cout << "Case #" << cas << ": " << flag << endl;
    }
    return 0;
}
