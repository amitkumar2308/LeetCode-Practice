class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;

        //8 direction
        vector<pair<int,int>> dirs;
        for(int dx=-1; dx<=1; dx++){
            for(int dy = -1; dy<=1; dy++){
                if(dx ==0 && dy==0) continue;
                dirs.push_back({dx,dy});
            }
        }

        // stores (row, col)
        queue<pair<int,int>> q;
        q.push({0,0});

        //visited matrix
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        visited[0][0] = true;

        int steps = 1;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0; i<sz; i++){
                auto[r,c] = q.front();
                q.pop();

                if(r == n-1 && c == n-1) return steps;

                for(auto[dx,dy]:dirs){
                    int nr = r+dx , nc = c+dy;

                    if(nr>=0 && nc>=0 && nr < n && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]){
                        visited[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
            steps++;
        }
    return -1;
    }
};