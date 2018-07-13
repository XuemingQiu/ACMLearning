package cn.polarsun;

import java.util.Arrays;
/**
 * 
 * @author polarsun
 *  思路：很简单啦，直接排序后，找出第一个和最后一个 位置不同的地方，差值就是结果
 */
public class ShortestUnsortedContinuousSubarray {
	public int findUnsortedSubarray(int[] nums) {
		int st = 0;
		int ed = 0;
		int n = nums.length;
		int[] tempNums = new int[n];
		for (int i = 0; i < n; i++) {
			tempNums[i] = nums[i];
		}
		Arrays.sort(tempNums);
		for (int i = 0; i < n; i++) {
			if (nums[i] != tempNums[i]) {
				st = i;
				break;
			}
		}
		for (int i = st; i < n; i++) {
			if (nums[i] != tempNums[i]) {
				ed = i;
			}
		}
		if (st == ed) {
			return 0;
		}
		return ed - st + 1;
	}
}
