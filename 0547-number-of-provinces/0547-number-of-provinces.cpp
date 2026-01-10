class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int provinces = 0;
        queue<int>q;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                provinces++;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int city = q.front(); q.pop();
                    for(int j=0 ;j<n; j++){
                        if(isConnected[city][j]==1 && !visited[j]){
                            visited[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};