class Solution {
public:
    int numSquares(int n) {
        queue<int>q;
        vector<bool> vis(n+1,false);
        int level = 0;
        q.push(n);
        vis[n] = true;

        while(!q.empty()){
            int size = q.size();
            level++;

            while(size--){
                int curr = q.front();
                q.pop();

                for(int i=1; i*i<=curr; i++){

                    int next = curr - (i*i);

                    if(next==0) return level;

                    if(!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }

                }
            }
        }
        return level;
    }
};