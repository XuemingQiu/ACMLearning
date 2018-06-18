package cn.polarsun;

public class TestTwoSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TwoSum test = new TwoSum();
		int[] nums = {2, 7, 11, 15};
		int target = 9;
		int[] ans = test.twoSum(nums,target);
		System.out.println(ans[0]+" "+ans[1]);
	}

}
