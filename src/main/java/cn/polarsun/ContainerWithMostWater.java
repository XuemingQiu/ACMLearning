package cn.polarsun;

public class ContainerWithMostWater {
	public int maxArea(int[] height) {
		int area = 0;
		int left = 0;
		int right = height.length - 1;
		while (left < right) {
			int tempHeight = Math.min(height[left], height[right]);
			area = Math.max(area, (right - left) * tempHeight);
			if (height[left] <= height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return area;
	}
}
