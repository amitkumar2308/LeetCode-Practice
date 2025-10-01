class Solution {
public:
    int rows,cols;
    void dfs(vector<vector<char>>& grid, int r, int c){
         if(r<0 || r>=rows || c<0 || c>=cols) return;
         if(grid[r][c]== '0')  return;

        grid[r][c] ='0';
        dfs(grid,r+1,c); //down vertical
        dfs(grid,r-1,c); //up vertical
        dfs(grid,r,c+1); //right horizontal
        dfs(grid,r,c-1); //left horizontal


    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;

        for(int i=0; i<rows; i++ ){
            for(int j=0;j<cols; j++){
                if(grid[i][j]=='1'){
                   ++count;
                   dfs(grid,i,j);
                }
            }
        }
    return count;  
    }
};