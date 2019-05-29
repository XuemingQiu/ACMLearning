#include <bits/stdc++.h>

using namespace std;
/**
   题目描述：给定T组测试数据，然后有N个字符构成的字符串，给出q个询问区间（l，r），然后问每个区间重组之后能不能构成个回文串
   
   思路：一个二位矩阵n×26,对于每次的询问，判断这段区间内每个字符A-Z出现的次数是否可以即可
        如果r-l+1是奇数，那么只允许出现一次奇数个数的字母
        如果r-l+1是偶数，那么不允许出现奇数次个数的字母
   技巧：先统计好当前到最开始的位置的每个字母对应的个数
*/
int t,n,q;
int l,r;
string s,s1;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    for(int cas=1; cas<=t; ++cas) {
        cin >> n >> q;
        s="#";
        cin >> s1;
        s += s1;
        vector<vector<int> > v(n+5);
        vector<int> temp(30);
        v[0] = temp;
        for(int i=1; i<=n; ++i) {
            temp[s[i]-'A']+=1;
            v[i] = temp;
        }
        int ans = 0;
        while(q--) {
            cin >> l >> r;
            int flag=0;
            if((r-l+1)%2) {
                flag = 1;

            }
            for(int i= 0; i < 26; ++i) {
                if((v[r][i]-v[l-1][i])%2) {
                    flag--;
                }
            }
            if(flag==0) {
                ans++;
            }
        }
        cout << "Case #" << cas << ": " << ans << endl;

    }
    return 0;

}
