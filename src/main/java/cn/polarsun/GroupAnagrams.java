package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

/**
 * 
 * @author polarsun
 * @method�� ͳ��ÿ���ַ�����26����ĸ�ĸ�����Ȼ����ö����������ͬ���ַ������Ѿ����뼯�ϵľͲ�Ҫ�ڼ����ˣ���ǵ���
 */
public class GroupAnagrams {
	public List<List<String>> groupAnagrams(String[] strs) {
		List<List<String>> ans = new ArrayList<List<String>>();
		boolean[] used = new boolean[strs.length];
		int[][] alphabat = new int[strs.length][27];
		for (int i = 0; i < strs.length; i++) {
			for (int j = 0; j < strs[i].length(); j++) {
				alphabat[i][strs[i].charAt(j) - 'a']++;
			}
		}
		for (int i = 0; i < strs.length; i++) {
			if (used[i]) {
				continue;
			}
			List<String> tempString = new ArrayList<String>();
			tempString.add(strs[i]);
			for (int j = i + 1; j < strs.length; j++) {
				if (!used[j]) {
					boolean flag = false;
					for (int k = 0; k < 26; k++) {
						if (alphabat[i][k] != alphabat[j][k]) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						tempString.add(strs[j]);
						used[j] = true;
					}
				}
			}
			ans.add(tempString);
		}
		return ans;
	}
}
