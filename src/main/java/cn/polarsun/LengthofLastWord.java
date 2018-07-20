package cn.polarsun;

class LengthofLastWord{
    public int lengthOfLastWord(String s) {
        String[] ans = s.split(" ");
        if(ans.length == 0){
            return 0;
        }
        return ans[ans.length-1].length();
    }
}
