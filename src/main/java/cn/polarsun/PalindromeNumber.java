package cn.polarsun;

public class PalindromeNumber {
	public boolean isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		long ans = 0;
		int xx = x;
		while (xx > 0) {
			ans *= 10;
			ans += xx % 10;
			xx /= 10;
		}
		return (ans == x) ? true : false;
	}
}
