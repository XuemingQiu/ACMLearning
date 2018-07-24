package cn.polarsun;

class ProductofArrayExceptSelf{
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] out = new int[n];
        int a = nums[n-1];
        out[n-1] = 1;
        for(int i = n-2;i >= 0;i--){
            out[i] = a;
            a *= nums[i];
        }
        a = 1;
        for(int i = 0;i < n;i++){
            out[i] = a*out[i];
            a *= nums[i];
        }
        return out;
    }
}
