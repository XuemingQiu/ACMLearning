package cn.polarsun;
class TopKFrequentElements{
  /*
   * 新知识：map，出了.get(),.put(),.containsKey(),还有新的方法，.getOrDefault() 默认个键值赋值为0
   *    在java中，优先队列的使用。
   *
   */
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> ans = new ArrayList<Integer>();
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>();
        for(int num : nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        PriorityQueue<Map.Entry<Integer,Integer>> pq = new PriorityQueue<>((a,b)-> b.getValue()-a.getValue());
        for(Map.Entry<Integer,Integer> keySet : mp.entrySet()) {
            pq.offer(keySet);
        }
        while(k>0){
            ans.add(pq.poll().getKey());
            k--;
        }
        return ans;
    }
}
