package cn.polarsun;
class Searcha2DMatrixII{
	/**
         哇，这个思路，完全想不到啊，左上到右下，不存在规律，但是左下到右上却是可以通过变化行列，发现规律的，
         每一个点（x,y） 他的（x-1，y）一定小于他，，（x，y+1）一定大于他，这样就可以递推式的查找了
         好奇妙的思路啦
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0 || matrix[0].length == 0){
            return false;
        }
        int col = 0;
        int row = matrix.length-1;
        while(row >= 0 && col < matrix[0].length) {
            if(target == matrix[row][col]) {
                return true;
            } else if(target < matrix[row][col]) {
                row--;
            } else if(target > matrix[row][col]) {
                col++;
            }
        }
        return false;
    }
}
