# 2019.12.17 A day with google

- 工作环境是真的很好，看中算法
- 面试官 Jinmin He
  - 第一题：给你一个01矩阵，让你找到所有的联通的1的个数块，一共有上下左右四个方向可以走
    - 思路简单：dfs或者bfs都可以，直接搜索就是了
  - 第二题：给你一个n*m的矩阵，刚开始全部是0，有一个add(x,y)操作，就是给（x,y）点将0设置为1，让你返回每次操作后1个联通块数。
    - 思路：我现场是用的map，set，然后用dfs深搜判断的，这是一种很笨的办法，面试官不想看见的
    - 正确思路应该是 并查集，现将路径搞成以为的 每个点（x，y）写成在一维里面 x*m+y，然后利用四个方向走的时候，并查集即可，代码是
```
#include <bits/stdc++.h>

using namespace std;
class UnionFind
{
public:
    map<int, int> fa;

public:
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    int merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
    bool isconnected(int x, int y)
    {
        return find(x) == find(y) ? 1 : 0;
    }
};

class CountConpenent
{

private:
    UnionFind uf;
    int n, m;

public:
    CountConpenent(int nn, int mm)
    {
        n = nn;
        m = mm;
    }
    int add(int x, int y)
    {
        int xdir[] = {-1, 0, 1, 0};
        int ydir[] = {0, -1, 0, 1};
        int pos = (x * m + y);
        uf.fa[pos] = pos;
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + xdir[i];
            int y1 = y + ydir[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m)
            {
                int tmppos = x1 * m + y1;
                if (uf.fa.find(tmppos) != uf.fa.end())
                {
                    uf.merge(pos, tmppos);
                }
            }
        }
        int ans = 0;
        for (auto t : uf.fa)
        {
            // cout << t.first << " " << t.second << endl;
            if (t.first == t.second)
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    CountConpenent op(2, 3);
    cout << op.add(0, 0) << endl;
    cout << op.add(0, 2) << endl;
    cout << op.add(1, 1) << endl;
    cout << op.add(1, 2) << endl;
    return 0;
}
```
- 总结：
  1. 代码风格问题：采用类的这种写法，代码可以重用，推荐的写法
  2. 要即时和面试官沟通，一些边界样例要有，还有就是代码测试的部分很少有人写