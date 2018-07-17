package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

/***
 * 
 * @author polarsun
 * @ÉîËÑ£º
 */
public class Subsets {
	List<List<Integer>> ans = new ArrayList<List<Integer>>();

	public List<List<Integer>> subsets(int[] nums) {
		int[] temp = new int[nums.length];
		dfs(nums, temp, 0, 0);
		return ans;
	}

	private void dfs(int[] nums, int[] temp, int index, int k) {
		List<Integer> temp2 = new ArrayList<Integer>();
		for (int i = 0; i < k; i++) {
			temp2.add(nums[temp[i]]);
		}
		if (!ans.contains(temp2)) {
			ans.add(temp2);
			// System.out.println("suoyin"+index);
		}
		if (index == nums.length) {
			return;
		}
		for (int i = index; i < nums.length; i++) {
			temp[k] = i;
			dfs(nums, temp, i + 1, k + 1);
		}
	}
}
