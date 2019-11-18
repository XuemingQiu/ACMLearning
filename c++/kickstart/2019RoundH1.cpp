#include <bits/stdc++.h>

using namespace std;
/*
 * 题目大意：让你计算一个研究者的的h指数，所谓h指数定义为：一个研究者有h篇论文，每篇论文至少h次引用。
 * 给定T组测试数据，第一行N代表论文数，第二行代表每篇论文的引用数，让你求出每篇论文发表后，该作者的h指数是多少
 * 
 * 思路：刚开始我以为可以用map直接记录一下引用的次数统计，倒序访问大于该作者有多少的目前文章数目的引用有多少，结果超时，时间复杂度
 * 遂改成用优先队列来操作上述过程。
 *
 */
int main()
{
    int T, N;
    int v;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas)
    {
        cin >> N;
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans;
        for (int i = 0; i < N; ++i)
        {
            cin >> v;
            q.push(v);
            if (i == 0)
            {
                ans.push_back(1);
                continue;
            }
            int tmp = 0;
            int anst = ans[i - 1] + 1;
			// 弹出队列里小于该h指数=anst的引用数
            while (!q.empty() && q.top() < anst)
            {
                // cout << q.top() << endl;
                q.pop();
            }

            anst = max(ans[i - 1], min((int)q.size(), anst));
            ans.push_back(anst);
        }
        cout << "Case #" << cas << ": ";
        for (int i = 0; i < N; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
