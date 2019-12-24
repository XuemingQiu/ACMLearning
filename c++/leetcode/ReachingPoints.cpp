#include<bits/stdc++.h>

using namespace std;

/**
 * 给定一个起点(x,y),通过两种变化(x+y,y)和(x,x+y)，问你得到(tx,ty)???
 * 思路：一看bfs,dfs搜索啊，可是数据量10^9，这根本不可行，所以看了题解，发现是用数学的办法，依据暴力的办法，我们是给x累加了很多次才得到tx
 * 然后可利用取余的办法来做，看代码，逐渐缩小了tx，ty
 *
 */

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) return false;
        while (tx >= sx && ty >= sy) {   // 因为tx = 之前的ty+tx得到，取余的话，就是删掉了累加n次的原因，这样最后得到原始x，y只采取一种操作构成的数字
            if(tx>ty) tx %= ty;
            else ty %= tx;
        }
        if (tx == sx) return (ty - sy) % sx == 0;
        if (ty == sy) return (tx - sx) % sy == 0;
        return false;
    }
};

int main(){
	return 0;
}
