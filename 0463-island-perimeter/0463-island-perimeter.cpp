class Solution {
public:
   
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int land = 0;
        int shared = 0;

        for(int i=0; i<rows; i++){
            for(int j=0;j<cols; j++){
                if(grid[i][j]==1){
                    land++;
                    if(j+1<cols && grid[i][j+1]==1)
                    shared++;
                    if(i+1<rows && grid[i+1][j]==1)
                    shared++;
                }
            }
        }
        return land*4 - shared*2;
    }
};