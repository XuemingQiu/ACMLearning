#include<bits/stdc++/h>

using namespace std;
/**
 * 题目大意：给定一串的等式和不等式，让你判断这些不懂呢过是或者不懂呢过是成不成立，主要就是传递性的判断
 * 思路：并查集，将所有的等式合并在一起，只需要判断不等式的成立性即可。
 */
class Solution {
public:
    int fa[27];
    int found(int x){
        return x==fa[x]?x:found(fa[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<27;++i){
            fa[i] = i;
        }
        vector<string>s;
        int t = 0;
        int n = equations.size();
        for(int i = 0;i < n;++i){
            if(equations[i][1]=='='){
                s.push_back(equations[i]);
                ++t;
            }
        }
        for(int i = 0;i < n;++i){
            if(equations[i][1]=='!'){
                s.push_back(equations[i]);
            }
        }
        equations = s;
        for(int i = 0;i < n;++i){
            int a = equations[i][0]-'a';
            int b = equations[i][3]-'a';
//            cout << a << " " << b << endl;
            if(a==b){
                if(equations[i][1]=='!'){
                    return false;
                }
            }else{
                int xx = found(a);
                int yy = found(b);
                if(xx==yy&&equations[i][1]=='!'){
                    return false;
                }else{
                    if(i < t){
                        fa[xx] = yy;
                    }
                }
            }
        }
        return true;
    }
};


int main(){
	return 0;
}
