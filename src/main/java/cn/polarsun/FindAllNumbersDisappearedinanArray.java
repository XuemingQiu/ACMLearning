package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * @author polarsun
 * @˼·�����֮�ѣ������Ĺ�˭����Ŭ����Զ����ô��֪
 *   �������뵽����ÿ��λ�õ�Ԫ�ص��뵽��Ӧ��λ�ã�������ʵ�ֵĹ����д��ڸ��ֵ����⣬�Լ�д�����Ǵ���������һֱд���ԣ����ο���discuss
 *   ��һ�ֽⷨ�ǣ�ȡ������discuss�и����ģ�����˵�Ǻܾ���ı�Ƿ��ˣ�ѧ����ѧ����
 */
public class FindAllNumbersDisappearedinanArray {
	public List<Integer> findDisappearedNumbers(int[] nums) {
		/**
		 * �ⷨһ����Ԫ�ص�����Ӧ��λ�þͿ�����
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
		 * �ⷨ����ȡ�������ܾ���Ľⷨ
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
