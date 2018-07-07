package cn.polarsun;

public class RemoveDuplicatesfromSortedArray {
	public int removeDuplicates(int[] nums) {
		if (nums.length == 0) {
			return 0;
		}
		int ans = 0;
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] != nums[ans]) {
				ans += 1;
				nums[ans] = nums[i];
			}
		}
		return ans + 1;
	}
}
