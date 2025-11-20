class Solution {
public:
    bool bfs(int src, int target, unordered_map<int,list<int>>& adj,int n){
         vector<bool> visited(n+1, false);
         queue<int>q;
         q.push(src);
         visited[src] = true;

         while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==target) return true;

            for(int nbr:adj[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
         }
         return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int,list<int>>adj(n+1);

        for(auto &e:edges){
            int u = e[0], v= e[1];

           // vector<bool>visited(n+1,false);

            if(!adj[u].empty() && !adj[v].empty()){
               if(bfs(u,v,adj,n))
               return e;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
    }
};