package cn.polarsun;

public class PalindromicSubstrings {
	public int countSubstrings(String s) {
		int len = s.length();
		int ans = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (s.charAt(i) == s.charAt(j)) {
					boolean flag = false;
					int st = i, ed = j;
					while (st < ed) {
						if (s.charAt(st) != s.charAt(ed)) {
							flag = true;
							break;
						}
						st++;
						ed--;
					}
					if (!flag) {
						ans++;
					}
				}
			}
		}
		return ans + len;
	}
}
