package cn.polarsun;

class PartitionEqualSubsetSum{
	/**
	 *@method :0-1背包的思想
	 */
	 public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        Arrays.sort(nums);
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        if(sum%2 == 1){
            return false;
        }
        int[] dp = new int[sum/2+1];
        for(int i = 0;i < n;i++){
            for(int v = sum/2;v >= nums[i];v--){
                dp[v] = Math.max(dp[v],dp[v-nums[i]]+nums[i]);
            }
        }
        return dp[sum/2]==sum/2?true:false;
    }
}
