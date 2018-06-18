package cn.polarsun;

public class LongestSubstringWithoutRepeatingCharacters {
	public int lengthOfLongestSubstring(String s) {
		int[] alpha = new int[500];
		int len = s.length();
		for (int i = 0; i < 500; i++) {
			alpha[i] = -1;
		}
		int st = -1;
		int ans = 0;
		for (int i = 0; i < len; i++) {
			int index = s.charAt(i);
			if (alpha[index] == -1) {
				ans = Math.max(ans, i - st);
			} else {
				st = Math.max(st, alpha[index]);
				ans = Math.max(ans, i - st);
			}
			alpha[index] = i;
			// System.out.println(ans);
		}
		return ans;
	}
}
