package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * @author polarsun
 * @思路：如此之难，上天饶过谁，不努力永远是那么无知
 *   很容易想到，把每个位置的元素调入到相应的位置，可是在实现的过程中存在各种的问题，自己写的老是错，结束条件一直写不对，最后参考了discuss
 *   另一种解法是：取负，在discuss中给出的，可以说是很精妙的标记法了，学到了学到了
 */
public class FindAllNumbersDisappearedinanArray {
	public List<Integer> findDisappearedNumbers(int[] nums) {
		/**
		 * 解法一：把元素调入相应的位置就可以了
		 */
		int n = nums.length;
		List<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				ans.add(i + 1);
			}
		}
		return ans;
		/**
		 * 解法二：取负法，很精妙的解法
		 */

//		int n = nums.length;
//		List<Integer> ans = new ArrayList<Integer>();
//		for (int i = 0; i < n; i++) {
//			int temp = Math.abs(nums[i]) - 1;
//			nums[temp] = (nums[temp] > 0) ? -nums[temp] : nums[temp];
//		}
//		for (int i = 0; i < n; i++) {
//			if (nums[i] > 0) {
//				ans.add(i + 1);
//			}
//		}
//		return ans;

	}
}
