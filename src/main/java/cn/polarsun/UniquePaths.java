package cn.polarsun;

/**
 * 
 * @author polarsun
 * @methods ���ѣ�ɵ��ɵ��100*100  ���еģ��������������Ǿ�dp��  ���ܵ��x��y��ֻ�У�x-1,y)��(x,y-1)������
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
