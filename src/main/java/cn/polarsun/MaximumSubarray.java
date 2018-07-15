package cn.polarsun;

public class MaximumSubarray {
	/**
	 * 
	 * @param nums
	 * @return
	 * @˼·����������еĺͣ��̶��㷨��ÿ�μ����Ե�ǰλ��Ϊ��β�����������кͱ�0���Ǿ�Ҫ+��ǰλ��Ԫ�� @ʱ�临�Ӷ�O(N)
	 */
	public int maxSubArray(int[] nums) {
//		int ans = Integer.MIN_VALUE, sum = 0;
//		for (int num : nums) {
//			sum += num;
//			ans = Math.max(ans, sum);
//			sum = Math.max(sum, 0);
//		}
//		return ans;
//		����2
		int ans = maxsequence2(nums, 0, nums.length);
		return ans;
	}

	/**
	 * 
	 * @param nums
	 * @return
	 * @���ε��뷨
	 * @ʱ�临�Ӷ� O(nlogn)
	 */
	public int maxsequence2(int a[], int l, int r) {
		if (l > r)
			return 0;
		if (l == r)
			return a[l];
		int mid = (l + r) >> 1;

		/* �����������������벿��,˳���ܷ� */
		int lmax = a[mid], lsum = 0;
		for (int i = mid; i >= l; i--) {
			lsum += a[i];
			lmax = Math.max(lsum, lmax);
		}

		/* ����������������Ұ벿�� */
		int rmax = a[mid + 1], rsum = 0;
		for (int i = mid + 1; i <= r; i++) {
			rsum += a[i];
			rmax = Math.max(rsum, rmax);
		}
		return Math.max(Math.max(lmax + rmax, maxsequence2(a, l, mid)), maxsequence2(a, mid + 1, r)); // �����������ֵ
	}

}
