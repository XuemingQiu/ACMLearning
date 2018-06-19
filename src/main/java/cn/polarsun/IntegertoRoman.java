package cn.polarsun;

import java.util.LinkedHashMap;
import java.util.Map;

public class IntegertoRoman {
	public String intToRoman(int num) {
		String ans = "";
		Map<Integer, String> mp = new LinkedHashMap<Integer, String>();
		mp.put(1000, "M");
		mp.put(900, "CM");
		mp.put(500, "D");
		mp.put(400, "CD");
		mp.put(100, "C");
		mp.put(90, "XC");
		mp.put(50, "L");
		mp.put(40, "XL");
		mp.put(10, "X");
		mp.put(9, "IX");
		mp.put(5, "V");	
		mp.put(4, "IV");
		mp.put(1, "I");
		for(Map.Entry<Integer,String>e:mp.entrySet()) {
			while(num/e.getKey() > 0) {
				ans += e.getValue();
				num -= e.getKey();
			}
		}
		return ans;
	}
}
