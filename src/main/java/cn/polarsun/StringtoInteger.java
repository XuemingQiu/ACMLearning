package cn.polarsun;

public class StringtoInteger {
	public int myAtoi(String str) {
		if (str.length() == 0) {
			return 0;
		}
		int MIN_VALUE = 0x80000000;
		int MAX_VALUE = 0x7fffffff;
		double ans = 0;
		int len = str.length();
		boolean flag = false, tag = true;
		int i = 0;
		while (i < len && str.charAt(i) == ' ') {
			i++;
		}
		for (; i < len; i++) {
			System.out.println(ans);
			if ((str.charAt(i) == '-' || str.charAt(i) == '+') && i + 1 < len && str.charAt(i + 1) >= '0'
					&& str.charAt(i + 1) <= '9' && tag) {
				flag = (str.charAt(i) == '-') ? true : false;
				continue;
			}
			if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
				ans *= 10;
				ans += str.charAt(i) - '0';
				tag = false;
			} else {
				break;
			}
		}
		System.out.println(ans);
		if (flag) {
			ans = -ans;
		}
		if (ans < MIN_VALUE) {
			return MIN_VALUE;
		}
		if (ans > MAX_VALUE) {
			return MAX_VALUE;
		}
		return (int) ans;
	}
}
