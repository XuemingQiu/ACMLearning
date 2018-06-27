package cn.polarsun;

public class LongestCommonPrefix {
	public String longestCommonPrefix(String[] strs) {
		String ans = "";
		int n = strs.length;
		if (n == 0) {
			return "";
		}
		int len = strs[0].length();
		for (int i = 1; i < n; i++) {
			len = Math.min(len, strs[i].length());
		}
		for (int i = 0; i < len; i++) {
			boolean flag = true;
			for (int j = 1; j < n; j++) {
				if (strs[j].charAt(i) != strs[0].charAt(i)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans += strs[0].charAt(i);
			} else {
				break;
			}
		}
		return ans;
	}
}
