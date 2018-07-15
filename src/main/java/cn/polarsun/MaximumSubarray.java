package cn.polarsun;

public class MaximumSubarray {
	/**
	 * 
	 * @param nums
	 * @return
	 * @思路：最大子序列的和，固定算法，每次计算以当前位置为结尾的连续子序列和比0大，那就要+当前位置元素 @时间复杂度O(N)
	 */
	public int maxSubArray(int[] nums) {
//		int ans = Integer.MIN_VALUE, sum = 0;
//		for (int num : nums) {
//			sum += num;
//			ans = Math.max(ans, sum);
//			sum = Math.max(sum, 0);
//		}
//		return ans;
//		方法2
		int ans = maxsequence2(nums, 0, nums.length);
		return ans;
	}

	/**
	 * 
	 * @param nums
	 * @return
	 * @分治的想法
	 * @时间复杂度 O(nlogn)
	 */
	public int maxsequence2(int a[], int l, int r) {
		if (l > r)
			return 0;
		if (l == r)
			return a[l];
		int mid = (l + r) >> 1;

		/* 求最大连续子序列左半部分,顺序不能反 */
		int lmax = a[mid], lsum = 0;
		for (int i = mid; i >= l; i--) {
			lsum += a[i];
			lmax = Math.max(lsum, lmax);
		}

		/* 求最大连续子序列右半部分 */
		int rmax = a[mid + 1], rsum = 0;
		for (int i = mid + 1; i <= r; i++) {
			rsum += a[i];
			rmax = Math.max(rsum, rmax);
		}
		return Math.max(Math.max(lmax + rmax, maxsequence2(a, l, mid)), maxsequence2(a, mid + 1, r)); // 返回三者最大值
	}

}
