package cn.polarsun;

import java.util.Stack;

public class ValidParentheses {
	public boolean isValid(String s) {
		int len = s.length();
		Stack<Character> stack = new Stack<Character>();
		for (int i = 0; i < len; i++) {
			if (s.charAt(i) == ')') {
				if (!stack.empty() && stack.pop() == '(') {
					continue;
				} else {
					return false;
				}
			} else if (s.charAt(i) == ']') {
				if (!stack.empty() && stack.pop() == '[') {
					continue;
				} else {
					return false;
				}
			} else if (s.charAt(i) == '}') {
				if (!stack.empty() && stack.pop() == '{') {
					continue;
				} else {
					return false;
				}
			} else {
				stack.push(s.charAt(i));
			}
		}
		if (stack.empty()) {
			return true;
		}
		return false;
	}
}
