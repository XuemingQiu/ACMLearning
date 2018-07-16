package cn.polarsun;

public class BestTimetoBuyandSelStock {
	/**
	 * 
	 * @param prices
	 * @return
	 * @˼·  ��������������
	 */
	public int maxProfit(int[] prices) {
//		int profit = 0;
//		for (int i = 0; i < prices.length; ++i) {
//			for (int j = i + 1; j < prices.length; ++j) {
//				profit = Math.max(profit, prices[j] - prices[i]);
//			}
//		}
//		return profit;
//		�ⷨ����
		int n = prices.length;
		if(n == 0){
            return 0;
        }
        int min = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            profit = Math.max(profit,prices[i]-min);
            min = Math.min(min,prices[i]);
        }
        return profit;
	}
}
