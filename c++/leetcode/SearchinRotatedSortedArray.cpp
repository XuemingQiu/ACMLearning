#include <bits/stdc++.h>


using namespace std;
/***
 *  题目大意：给定一个旋转数组吗，也就是有序数组从某一段隔开 连接在最后面 例如 ： 5 4 1 2 3，问你一个target在不在该数组中
 *  思路：二分，这个容易想到，毕竟两部分都是有序的
 *  总结一下： 对于left<right   必须：left = mid-1,right = mid
 *             对于left<=right        left = mid-1,right = mid-1
 *
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int left=0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid] < nums[right]){  // 说明右半部分是有序的
                if(nums[mid]<target && nums[right] >= target){ // 进行 target 二分
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else{
                if(nums[mid]>target && nums[left] <= target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};
int main(){
    return 0;
}
