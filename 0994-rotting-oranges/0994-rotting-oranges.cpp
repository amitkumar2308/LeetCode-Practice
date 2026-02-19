class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
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
        int minutes = 0;

        while(!q.empty()&&fresh>0){
            int size = q.size();

            while(size--){
              auto[x,y] = q.front();
              q.pop();

              for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){

                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx,ny});

                }
              }
            }
        minutes++;
        }
        if(fresh>0)
           return -1;
        return minutes;
    }
};