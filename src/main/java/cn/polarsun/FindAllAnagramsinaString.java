package cn.polarsun;
class FindAllAnagramsinaString{
	/**
	 * @method 26个字母统计检验即可
	 */
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<Integer>();
        int[] alphabet = new int[27];
        int len = p.length();
        for(int i = 0;i < len;i++){
            alphabet[p.charAt(i)-'a']++;
        }
        int lens = s.length();
        int[] alphabets = new int[27];
        for(int i = 0;i < lens;i++){
            if(i < len-1){
                alphabets[s.charAt(i)-'a']++;
            }else{
                alphabets[s.charAt(i)-'a']++;
                boolean flag = true;
                for(int j = 0 ;j < 26;++j){
                    if(alphabet[j] != alphabets[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.add(i-len+1);
                }
                alphabets[s.charAt(i-len+1)-'a']--;
            }
        }
        return ans;
    }
}
