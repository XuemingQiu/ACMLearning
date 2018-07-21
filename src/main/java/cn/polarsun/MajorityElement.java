package cn.polarsun;

class MajorityElement{
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>();
        int n = nums.length;
        int ans = 0;
        int min = Integer.MIN_VALUE;
        for(int i = 0;i < n;i++){
            int t = 0;
            if(mp.containsKey(nums[i])){
                t = mp.get(nums[i])+1;
               
            }else{
                t = 1;
            }
            if(min < t){
                ans = nums[i];
                min = t;
            }
            mp.put(nums[i],t);
        }
        return ans;
    }
}
