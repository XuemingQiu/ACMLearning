package cn.polarsun;

public class ZigZagConversion {
	public String convert(String s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		String ans = "";
		String[] gra = new String[numRows + 2];
		for (int i = 0; i < numRows + 2; i++) {
			gra[i] = "";
		}
		int i = 0, row = 0, flag = 1;
		while (i < s.length()) {
			if (flag == 1) {
				gra[row] += s.charAt(i);
				row++;
				if (row == numRows) {
					row -= 2;
					flag = 0;
				}
			} else {
				gra[row] += s.charAt(i);
				row--;
				if (row == -1) {
					row += 2;
					flag = 1;
				}
			}
			i++;
		}

		for (String str : gra) {
			ans += str;
		}
		return ans;
	}
}
