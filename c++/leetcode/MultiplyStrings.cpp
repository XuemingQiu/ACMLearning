/*
 * 题目意思：很简单的意思，给定两个数字构成字符串，让你求这个字符串的乘积
 * 思路：模拟乘法的计算办法，用第二个字符串的个位数*第一个数字的每一位，并且保持进不进位。
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        int n = num1.size();
        int m = num2.size();
        int idx = 0;
        vector<int>pos(n+m+1); // 结果不会超过你你n+m+1位
        for(int i = n-1;i>=0;--i){
            int p = idx;//每次乘法都会向前面挪一位，用来记录挪到了哪一位
            int flag = 0;//进位标志
            for(int j = m-1;j>=0;--j){
                flag += (num2[j]-'0')*(num1[i]-'0')+pos[p];
                pos[p] = flag%10;
                flag /= 10;
                p++;
            }
            if(flag>0){
                pos[p] = flag;
            }
            idx++;
        }
        //逆转得到结果
        idx = n+m;
        while(idx >= 0 && pos[idx]==0){
            idx--;
            continue;
        }
        while(idx>=0){
            ans += pos[idx]+'0';
            idx--;
        }
        if(ans.size() == 0){
            ans += "0";
        }
        
        return ans;
    }
};

int main(){
    Solution so;
    string ans =so.multiply("123","456");
    cout << ans << endl;
    return 0;
}
