package cn.polarsun;

public class HammingDistance {
	public int hammingDistance(int x, int y) {
		int ans = 0;
		x ^= y;
		while (x != 0) {
			if (x % 2 == 1) {
				ans++;
			}
			x = (x >> 1);
		}
		return ans;
	}
}
