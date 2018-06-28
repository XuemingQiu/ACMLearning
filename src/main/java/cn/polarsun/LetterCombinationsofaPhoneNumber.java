package cn.polarsun;

import java.util.ArrayList;
import java.util.List;

public class LetterCombinationsofaPhoneNumber {
	int n;
	List<String> ans = new ArrayList<String>();

	public List<String> letterCombinations(String digits) {
		n = digits.length();
		if (n == 0) {
			return ans;
		}
		dfs(0, "", digits);
		return ans;
	}

	public void dfs(int i, String temp, String digits) {
		if (i == n) {
			ans.add(temp);
			return;
		}
		if (digits.charAt(i) == '2') {
			dfs(i + 1, temp + 'a', digits);
			dfs(i + 1, temp + 'b', digits);
			dfs(i + 1, temp + 'c', digits);
		}
		if (digits.charAt(i) == '3') {
			dfs(i + 1, temp + 'd', digits);
			dfs(i + 1, temp + 'e', digits);
			dfs(i + 1, temp + 'f', digits);
		}
		if (digits.charAt(i) == '4') {
			dfs(i + 1, temp + 'g', digits);
			dfs(i + 1, temp + 'h', digits);
			dfs(i + 1, temp + 'i', digits);
		}
		if (digits.charAt(i) == '5') {
			dfs(i + 1, temp + 'j', digits);
			dfs(i + 1, temp + 'k', digits);
			dfs(i + 1, temp + 'l', digits);
		}
		if (digits.charAt(i) == '6') {
			dfs(i + 1, temp + 'm', digits);
			dfs(i + 1, temp + 'n', digits);
			dfs(i + 1, temp + 'o', digits);
		}
		if (digits.charAt(i) == '7') {
			dfs(i + 1, temp + 'p', digits);
			dfs(i + 1, temp + 'q', digits);
			dfs(i + 1, temp + 'r', digits);
			dfs(i + 1, temp + 's', digits);
		}
		if (digits.charAt(i) == '8') {
			dfs(i + 1, temp + 't', digits);
			dfs(i + 1, temp + 'u', digits);
			dfs(i + 1, temp + 'v', digits);
		}
		if (digits.charAt(i) == '9') {
			dfs(i + 1, temp + 'w', digits);
			dfs(i + 1, temp + 'x', digits);
			dfs(i + 1, temp + 'y', digits);
			dfs(i + 1, temp + 'z', digits);
		}
	}
}
