package cn.polarsun;

class NumberofIslands{
	int[] xx = {0,-1,0,1};
    int[] yy = {-1,0,1,0};
    int ans = 0;
    public int numIslands(char[][] grid) {
        for(int i = 0;i < grid.length;i++){
            for(int j = 0;j < grid[i].length;j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    dfs(i,j,grid);
                    ans += 1;
                }
            }
        }
        return ans;
    }
    private void dfs(int x,int y,char[][] grid){
        for(int i=0;i < 4;i++){
            int x1 = x+xx[i];
            int y1 = y+yy[i];
            if(x1 >= 0 && x1 < grid.length && y1 >=0 && y1 < grid[0].length && grid[x1][y1] == '1'){
                grid[x1][y1] = '0';
                dfs(x1,y1,grid);
            }
        }
    }
}
