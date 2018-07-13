package cn.polarsun;

import java.util.Arrays;

/**
 * 
 * @author polarsun 
 * 题意比较难理解，题目要求，相同的任务之间的间隔数不小n， 
 * 那么先安排个数对多的任务，每两个相隔n出现
 * 如果有好几个任务的个数相同的话，看成一个模块,每个模块的长度为n+1
 * 最后在加上，每个模块自己内部的大小
 */

public class TaskScheduler {
	public int leastInterval(char[] tasks, int n) {
		int len = tasks.length;
		int[] task = new int[26];
		for (int i = 0; i < len; i++) {
			task[tasks[i] - 'A']++;
		}
		Arrays.sort(task);
		int temp = 0;
		for (int i = 25; i >= 0; i--) {
			if (task[i] == task[25]) {
				temp++;
			}
		}
		return Math.max(len, (task[25] - 1) * (n + 1) + temp);
	}
}
