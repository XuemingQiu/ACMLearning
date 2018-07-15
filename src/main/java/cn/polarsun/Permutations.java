package cn.polarsun;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
/**
 * 
 * @author polarsun
 * 再生成全排列算法中，java没找到内在的全排列函数
 * 在c++中存在这样函数，pytho中也类似
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
