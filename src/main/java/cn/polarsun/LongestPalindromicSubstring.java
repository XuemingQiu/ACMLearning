package cn.polarsun;

public class LongestPalindromicSubstring {
	public boolean judge(String s, int st, int ed) {
		while (st < ed) {
			if (s.charAt(st) != s.charAt(ed)) {
				return false;
			}
			st++;
			ed--;
		}
		return true;
	}
	public String longestPalindrome(String s) {
		int len = s.length();
		int ans = 0;
		String ans2 = "";
		for (int i = 0; i < len; i++) {
			for (int j = i + ans; j < len; j++) {
				if (judge(s, i, j)) {
					ans = j - i + 1;
					ans2 = s.substring(i, j + 1);
				}
			}
		}
		return ans2;
	}
}
