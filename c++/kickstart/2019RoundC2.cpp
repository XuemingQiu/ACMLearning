#include <bits/stdc++.h>
/**
    ��Ŀ����������һ��r*c�ľ�������ÿ��������һ��Ȩ�أ�
              ��Ϊ��ͬһ���У�����֮��������С��Ȩ�ز����K���ɵ�С���Σ����еĻ������������빹�ɾ��Σ�����Ϊgood.
              �ҵ������������������Ŀ���
    ����������
      R=3,C=3,K=0
      1 2 2 3
      1 2 2 2
      1 3 3 3
      �� ans=6����һ��2 2���ڶ���2 2��������3 3
    ˼·��1>.ֱ�ӱ���ö����㣬Ȼ�������sc���ж��Ը���㣬���Ϊsc�ľ��Σ��ܹ��ɵ�������������д��ʱ�临�Ӷ����ߣ��ᳬʱ
              �Ż���һ�£����ֿ�ȣ�������Ȼ�ᳬʱ
          2>. ��������ı���˼�룬ֻ��Ҫ��������Ż��ˡ�
              (1).�����Ǳ����ԣ�x��y���յ㣬��x��һ���У���¼����y����good����Сλ�ã������͵õ�һ����ά�ľ��󣬼�¼���Ըõ�Ϊ��
              ��������õ㹹��good����Сλ�á�
              (2).���������ľ�������ֻ��Ҫ�ж϶��еĵ������ö��ÿһ���㣬Ȼ���ж��Ըõ�����Ϊ�յ�ģ����������������������ļ���
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
