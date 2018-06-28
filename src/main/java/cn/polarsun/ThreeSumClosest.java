package cn.polarsun;

import java.util.Arrays;

public class ThreeSumClosest {
	public int threeSumClosest(int[] nums, int target) {
		int ansDis = Integer.MAX_VALUE;
		int n = nums.length;
		if (n == 3) {
			return nums[0] + nums[1] + nums[2];
		}
		Arrays.sort(nums);
		int ans = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < n - 2; i++) {
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				int temp = nums[i] + nums[left] + nums[right];
				if (temp == target) {
					return temp;
				} else if (temp < target) {
					left++;
				} else {
					right--;
				}
				if (ansDis > Math.abs(temp - target)) {
					ansDis = Math.abs(temp - target);
					ans = temp;
				}
			}
		}
		return ans;
	}
}
