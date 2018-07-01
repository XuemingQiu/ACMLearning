package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {
	List<String> ans = new ArrayList<String>();

	public List<String> generateParenthesis(int n) {
		String str = "";
		dfs(n, 0, 0, str);
		return ans;
	}

	public void dfs(int n, int u, int s, String str) {
		if (u == n && s == n) {
			ans.add(str);
			return;
		}
		if (u < n) {
			dfs(n, u + 1, s, str + '(');
		}
		if (u > s && s < n) {
			dfs(n, u, s + 1, str + ')');
		}
	}
}
