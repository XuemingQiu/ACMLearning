package cn.polarsun;

/**
 * 
 * @author polarsun
 * @method ����������У���ÿһ����β��λ�ã�ȥ�鿴��ǰ�������λ���ϱ���С�ĸ���
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
