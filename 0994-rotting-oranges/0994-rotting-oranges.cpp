class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                   q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        
        int min = 0;
        while(!q.empty()&&fresh>0){
            int size = q.size();

            while(size--){
                auto[x,y] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];

                    if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }

                }
            }
            min++;
        }

        if(fresh>0) return -1;
        return min;
    }
};