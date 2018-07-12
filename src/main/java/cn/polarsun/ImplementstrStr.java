package cn.polarsun;

public class ImplementstrStr {
	public int strStr(String haystack, String needle) {
		int len = haystack.length();
		int len2 = needle.length();
		for (int i = 0; i < len - len2; i++) {
			if (needle.equals(haystack.substring(i, i + len2))) {
				return i;
			}
		}
		return -1;
	}
}
