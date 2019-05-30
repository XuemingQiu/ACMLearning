#include <bits/stdc++.h>
/**
    题目描述：给定一个r*c的矩形网格，每个网格都有一个权重，
              认为在同一行中，网格之间的最大最小的权重差不超过K构成的小矩形，多行的话联合起来必须构成矩形，则认为good.
              找到满足上述条件的最大的块数
    举例：比如
      R=3,C=3,K=0
      1 2 2 3
      1 2 2 2
      1 3 3 3
      则 ans=6，第一行2 2，第二行2 2，第三行3 3
    思路：1>.直接暴力枚举起点，然后暴力宽度sc，判断以该起点，宽度为sc的矩形，能够成的最大块数，这种写法时间复杂度塔高，会超时
              优化了一下，二分宽度，但是依然会超时
          2>. 有了上面的暴力思想，只需要考虑如何优化了。
              (1).那我们暴力以（x，y）终点，在x这一行中，记录能与y构成good的最小位置，这样就得到一个二维的矩阵，记录了以该点为终
              该行能与该点构成good的最小位置。
              (2).有了上述的矩阵，我们只需要判断多行的的情况，枚举每一个点，然后判断以该点列作为终点的，连续多少行是满足条件的即可
*/
using namespace std;

int t,r,c,k,w;
vector<vector<int>>v;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    for(int cas=1; cas<=t; ++cas) {
        v.clear();
        cin >> r >> c >> k;
        for(int i = 0; i<r; ++i) {
            vector<int>temp;
            for(int j=0; j < c; ++j) {
                cin >> w;
                temp.push_back(w);
            }
            v.push_back(temp);
        }
        ans = 0;
        vector<vector<int>>position(r);
        for(int i=0; i<r; ++i) {
            vector<int>tempp(c);
            for(int j=0; j<c; ++j) {
                int mi = v[i][j];
                int mx = v[i][j];
                int lo = j;
                for(int sc=j-1; sc>=0; --sc) {
                    mx = max(v[i][sc],mx);
                    mi = min(v[i][sc],mi);
                    if(mx-mi > k) {
                        break;
                    }
                    lo = sc;
                }
                tempp[j] = lo;
            }
            position[i] = tempp;
        }
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                int temp = position[i][j];
                for(int sr = i;sr<r;++sr){
                    temp = max(temp,position[sr][j]);
                    ans = max(ans,(sr-i+1)*(j-temp+1));
                }
            }
        }
        cout << "Case #"<<cas << ": " << ans <<endl;
    }
    return 0;
}
