package cn.polarsun;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ThreeSum {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
		Arrays.sort(nums);
		int n = nums.length;
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1, right = n - 1;
			while (left < right) {
				if (nums[left] + nums[right] + nums[i] == 0) {
					List<Integer> temp = new ArrayList<Integer>();
					// System.out.println(nums[i]+" "+nums[left]+" " +nums[right]);
					temp.add(nums[i]);
					temp.add(nums[left]);
					temp.add(nums[right]);
					ans.add(temp);
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				} else if (nums[left] + nums[right] + nums[i] < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		return ans;
	}
}
