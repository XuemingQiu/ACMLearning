package cn.polarsun;
class JumpGame{
	/**
         @method:有点像线段树，但是似乎不用线段树，直接更新也是可以的,再去判断
    	*/
    public boolean canJump(int[] nums) {
        if(nums.length == 1){
            return true;
        }
        boolean[] used = new boolean[nums.length];
        used[0] = true;
        for(int i = 0;i < nums.length ;i++){
            if(used[i] ){
                for(int j = i+1;j < Math.min(i+nums[i]+1,nums.length);j++){
                    used[j] = true;
                    if(j == nums.length-1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
