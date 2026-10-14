class Solution {
public:

    bool bfs(int source,int destination, unordered_map<int,list<int>>& adj,vector<bool> &visited){
         queue<int>q;
         q.push(source);

         visited[source] = true;


         while(!q.empty()){
            int node  = q.front();
            q.pop();

            if(node == destination) return true;


            for(int nghbr:adj[node]){
                if(!visited[nghbr]){
                    visited[nghbr]=true;
                    q.push(nghbr);
                }
            }
           
         }
          return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         unordered_map<int,list<int>>adj(n);
         vector<bool>visited(n,false);

         for(auto &edge:edges){
             int u = edge[0];
             int v = edge[1];

             adj[u].push_back(v);
             adj[v].push_back(u);

         }

         return bfs(source,destination,adj,visited);

    }
};