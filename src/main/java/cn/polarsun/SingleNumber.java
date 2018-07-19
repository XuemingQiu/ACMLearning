package cn,polarsun;

class SingleNumber{
    /*
       @method:xor has been selected,because 0^N = N, N^N = 0
    */
    public int singleNumber(int[] nums) {
        int ans = 0;
        for(int n : nums){
            ans ^= n;
        }
        return ans;
    }
}
