package cn.polarsun;

import java.util.Arrays;

/**
 * 
 * @author polarsun 
 * ����Ƚ�����⣬��ĿҪ����ͬ������֮��ļ������Сn�� 
 * ��ô�Ȱ��Ÿ����Զ������ÿ�������n����
 * ����кü�������ĸ�����ͬ�Ļ�������һ��ģ��,ÿ��ģ��ĳ���Ϊn+1
 * ����ڼ��ϣ�ÿ��ģ���Լ��ڲ��Ĵ�С
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
