package cn.polarsun;

import java.util.regex.*;

public class RegularExpressionMatching {
	public boolean isMatch(String s, String p) {
		boolean flag = Pattern.matches(p, s);
		return flag;
	}
}
