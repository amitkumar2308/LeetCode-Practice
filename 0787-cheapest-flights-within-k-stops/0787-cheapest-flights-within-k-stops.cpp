class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n+1,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&vec:flights){
            int u = vec[0];
            int v = vec[1];
            int price = vec[2];

            adj[u].push_back({v,price});
        }

        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;

        int steps = 0;

        while(!q.empty()&& steps<=k){
            int N = q.size();

            while(N--){
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                for(auto &p:adj[node]){
                    int x = p.first;
                    int d = p.second;
                    
                    if(dist[x]>cost+d){
                        dist[x] = cost+d;
                        q.push({x,cost+d});
                    }

                }
            }
             steps++;
        }
       

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};