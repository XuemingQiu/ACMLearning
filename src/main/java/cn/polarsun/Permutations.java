package cn.polarsun;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
/**
 * 
 * @author polarsun
 * ������ȫ�����㷨�У�javaû�ҵ����ڵ�ȫ���к���
 * ��c++�д�������������pytho��Ҳ����
 */
public class Permutations {
	List<List<Integer>> ans = new ArrayList<List<Integer>>();

	public List<List<Integer>> permute(int[] nums) {
		Set<Integer> s = new LinkedHashSet<Integer>();
		dfs(nums, s);
		return ans;
	}

	private void dfs(int[] nums, Set<Integer> s) {
		if (s.size() == nums.length) {
			List<Integer> temp = new ArrayList<Integer>();
			for (int i : s) {
				temp.add(nums[i]);
			}
			ans.add(temp);
			return;
		}
		for (int i = 0; i < nums.length; i++) {
			if (!s.contains(i)) {
				s.add(i);
				dfs(nums, s);
				s.remove(i);
			}
		}
	}
}
