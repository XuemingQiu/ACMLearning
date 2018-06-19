package cn.polarsun;

public class ReverseInteger {
	public int reverse(int x) {
		long INT_MAX = 2147483647;
		long INT_MIN = -2147483648;
		long xx = x;
		if (x < 0) {
			xx = -xx;
		}
		long ans = 0;
		while (xx != 0) {
			ans *= 10;
			ans += xx % 10;
			xx /= 10;
		}
		if (x < 0) {
			ans = -ans;
		}
		if (ans > INT_MAX || ans < INT_MIN) {
			return 0;
		}
		return (int) ans;
	}
}
