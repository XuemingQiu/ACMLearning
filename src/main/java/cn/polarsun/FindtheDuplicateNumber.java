package cn.polarsun;

/**
 * 
 * @author polarsun
 * @˼· ��https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/��ͬ��˼·
 * @�ⷨ��Ҳ���ƾ��忴FindAllnumbersDisappearedinanArray.java����
 */
public class FindtheDuplicateNumber {
	public int findDuplicate(int[] nums) {
		int n = nums.length;
		for (int i = 0; i < n; i++) {
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return nums[i];
			}
		}
		// return ans;
		return 0;
	}
}
