package cn.polarsun;

class KthLargestElementinanArray{
	public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}
