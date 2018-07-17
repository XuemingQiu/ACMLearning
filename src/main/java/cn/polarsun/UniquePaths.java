package cn.polarsun;

/**
 * 
 * @author polarsun
 * @methods 深搜，傻不傻，100*100  不行的，哈哈哈哈，，那就dp吧  ，能到达（x，y）只有（x-1,y)和(x,y-1)两点啦
 */
public class UniquePaths {
	public int uniquePaths(int m, int n) {
		int dp[][] = new int[m + 1][n + 1];
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (j == 1 || i == 1) {
					dp[i][j] = 1;
				} else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m][n];
	}
}
