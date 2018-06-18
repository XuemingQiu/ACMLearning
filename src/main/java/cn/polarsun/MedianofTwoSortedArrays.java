package cn.polarsun;

public class MedianofTwoSortedArrays {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int l1 = nums1.length;
		int l2 = nums2.length;
		int tol = l1 + l2;
		if (tol == 0) {
			return 0.0;
		}
		int[] ans = new int[tol / 2 + 5];
		int k = 0, i = 0, j = 0;
		while (i < l1 && j < l2 && k <= tol / 2) {
			if (nums1[i] <= nums2[j]) {
				ans[k++] = nums1[i++];
				System.out.println(ans[k - 1]);
			} else {
				ans[k++] = nums2[j++];
			}
		}
		while (k <= tol / 2 && i < l1) {
			ans[k++] = nums1[i++];
		}
		while (k <= tol / 2 && j < l2) {
			ans[k++] = nums2[j++];
		}
		return (tol % 2 == 0) ? (ans[k - 1] + ans[k - 2]) * 1.0 / 2 : ans[k - 1];
	}
}
