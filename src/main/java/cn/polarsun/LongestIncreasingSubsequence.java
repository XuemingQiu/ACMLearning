package cn.polarsun;

/**
 * 
 * @author polarsun
 * @method 最长上升子序列，对每一个结尾的位置，去查看其前面的所有位置上比它小的个数
 * @complexity O(n^2)
 */
public class LongestIncreasingSubsequence {
	public int lengthOfLIS(int[] nums) {
		int n = nums.length;
		if (n == 0) {
			return 0;
		}
		int[] dp = new int[n];
		int ans = 1;
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (nums[j] < nums[i]) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
					ans = Math.max(ans, dp[i]);
				}
			}
		}
		return ans;
	}
}
