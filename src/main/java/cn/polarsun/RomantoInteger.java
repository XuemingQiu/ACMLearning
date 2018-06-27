package cn.polarsun;

import java.util.LinkedHashMap;
import java.util.Map;

public class RomantoInteger {
	 public int romanToInt(String s) {
		 int ans = 0;
		 Map<String, Integer> mp = new LinkedHashMap<String, Integer>();
			mp.put( "M",1000);
			mp.put( "CM",900);
			mp.put( "D",500);
			mp.put( "CD",400);
			mp.put( "C",100);
			mp.put( "XC",90);
			mp.put( "L",50);
			mp.put( "XL",40);
			mp.put( "X",10);
			mp.put( "IX",9);
			mp.put( "V",5);	
			mp.put( "IV",4);
			mp.put( "I",1);
			int len = s.length();
			int i = 0;
			for(;i<len-1;i++) {
				String temp = ""+s.charAt(i)+s.charAt(i+1);
				if(mp.containsKey(temp)) {
					ans += mp.get(temp);
					i++;
				}else {
					temp = ""+s.charAt(i);
					ans += mp.get(temp);
				}
			}
			if(i == len-1) {
				String temp = ""+s.charAt(i);
				ans += mp.get(temp);
			}
			return ans;
	    }
	 
}
