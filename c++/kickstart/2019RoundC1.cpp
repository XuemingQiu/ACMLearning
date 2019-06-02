#include<bits/stdc++.h>
/**
 * 题目意思：给定t组测试数据，在一个R*C的网格上，给定一列操作，东西南北，并且如果某一点机器人已走过了，那么他必须按照当前给定的方向继续向前，直到没有走过的点即可。
 * 思路：就是模拟嘛，然后每行开个set来判断走没走过。
 * ps：
 *     我用了set，超时，最后经过大佬提示要用unordered_set,也是很神奇了
 *     set是实现了红黑树的二叉检索树，是有序的
 *     unorder_set使用的是哈希表，是无序的
 *     所以在在这道题目实现的上话，unordered_set更会节省时间
 **/

using namespace std;

int t;
int n,r,c,ansr,ansc;
string step;

int main() {

    cin >> t;
    for(int cas=1; cas<=t; ++cas) {
        cin >> n >> r >> c >> ansr >> ansc;
        vector<unordered_set<int> >s(r+1);
        cin >> step;
        s[ansr].insert(ansc);
        for(int i = 0; i < n; i++) {
            if(step[i] == 'N') {
                while(s[ansr].find(ansc) != s[ansr].end()) {
                    ansr-=1;
                }
                s[ansr].insert(ansc);
                continue;
            }
            if(step[i] == 'S') {
                while(s[ansr].find(ansc) != s[ansr].end()) {
                    ansr+=1;
                }
                s[ansr].insert(ansc);
                continue;
            }
            if(step[i] == 'W') {
                while(s[ansr].find(ansc) != s[ansr].end()) {
                    ansc-=1;
                }
                s[ansr].insert(ansc);
                continue;
            }
            if(step[i] == 'E') {
                while(s[ansr].find(ansc) != s[ansr].end()) {
                    ansc+=1;
                }
                s[ansr].insert(ansc);
                continue;
            }
        }
        cout << "Case #" << cas << ": " <<  ansr << " " << ansc << endl;
        s.clear();
    }
    return 0;
}

