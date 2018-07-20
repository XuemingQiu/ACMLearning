package cn.polarsun;

class SpiralMatrix{
	/*
	 * 简单的模拟
	 */
     public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer>();
        int n = matrix.length;
        if(n == 0){
            return ans;
        }
        int m = matrix[0].length;
        int row = 0,col = 0;
        int cycle = 0;
        int u = 0;
        while(u < n*m){
            while(col < m-cycle && u < n*m){
                ans.add(matrix[row][col++]);
                u++;
            }
            col--;
            row++;
            while(row < n-cycle&& u < n*m){
                ans.add(matrix[row++][col]);
                u++;
            }
            row--;
            col--;
            while(col >= cycle&& u < n*m){
                ans.add(matrix[row][col--]);
                u++;
            }
            col++;
            row--;
            while(row > cycle&& u < n*m){
                ans.add(matrix[row--][col]);
                u++;
            }
            row++;
            col++;
            cycle++;
        }
        return ans;
    }
}
