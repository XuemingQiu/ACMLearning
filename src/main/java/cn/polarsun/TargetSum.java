package cn.polarsun;

public class TargetSum {
	int ans = 0;

	public int findTargetSumWays(int[] nums, int S) {
		dfs(nums, S, 0);
		return ans;
	}

	public void dfs(int[] nums, int S, int index) {
		if (S == 0 && index == nums.length) {
			ans++;
			return;
		}
		if (index == nums.length) {
			return;
		}
		dfs(nums, S - nums[index], index + 1);
		dfs(nums, S + nums[index], index + 1);
	}
}
