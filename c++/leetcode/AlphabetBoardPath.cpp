#include <bits/stdc++.h>

using namespace std;
/*
 * 题目大意：给定一个图。从a-z,每5个一行，最后一行只剩一个z.给定一个单词，让你找到合适的路径会构成该单词，只能上下左右走，欲打破该单词字母加个“！”
 * 思路：以为是个深搜，不料是个暴力判断，如果目标函数的字母比当前位置的字母大，那就向右或者向下走。否则，向上和向下，具体判断如代码所示。
 */
class Solution {
    string ans = "";
    void dfs(string gra[],string target){
        int x=0,y=0,cur = 0;
        while(cur < target.size()){
             while(cur < target.size() && target[cur] == gra[x][y]){
                ans += "!";
                cur++;
             }
            if(cur >= target.size()){
                break;
            }
            if(target[cur] == 'z'){
                while(y!=0){
                    ans += 'L';
                    y-=1;
                }
            }
            if(target[cur] > gra[x][y]){
                if(target[cur]-gra[x][y] > gra[x][4]-gra[x][y]){
                    ans += 'D';
                    x += 1;
                }else{
                    ans += 'R';
                    y+=1;
                }
            }else{
                if(gra[x][y]-target[cur] > gra[x][y]-gra[x][0]){
                    ans += 'U';
                    x -= 1;
                }else{
                    ans += 'L';
                    y-=1;
                }
            }
        }

    }
public:
    string alphabetBoardPath(string target) {
        string gra[] = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z####"};
        ans = "";
        string temp = "";
        dfs(gra,target);
        return ans;
    }
};

int main(){
	Solution so;
	cout << so.alphabetBoardPath("leet") << endl;
}
