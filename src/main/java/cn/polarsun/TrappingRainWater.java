package cn.polarsun;
class TrappingRainWater{
	/*
         @method:  计算每一点的左侧的最高值和右侧的最大值，然后取最小值与当前的高度差，即使该点这里能够容纳水量的多少
    	*/
    public int trap(int[] height) {
        int n = height.length;
        if(n == 0){
            return 0;
        }
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i= 1;i < n;i++){
            left[i] = Math.max(left[i-1],height[i]);
        }
        for(int i = n-2;i >= 0;i--){
            right[i] = Math.max(right[i+1],height[i]);
        }
        int ans = 0;
        for(int i = 0;i < n-1;i++){
            if(height[i] < Math.min(left[i],right[i])){
                ans += Math.min(left[i],right[i])-height[i];
            }
        }
        return ans;
    }
}
