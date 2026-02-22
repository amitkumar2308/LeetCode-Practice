class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);

         for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
         }

         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
         pq.push({0,src,0});

         vector<int>stops(n,INT_MAX);

         while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int node = top[1];
            int stop = top[2];

            if(node==dst) return cost;

            if(stop>k || stop>stops[node]) continue;

            stops[node] = stop;

            for(auto &it:adj[node]){
                int nextNode = it.first;
                int price = it.second;

                pq.push({cost+price,nextNode,stop+1});
            }
         }
         return -1;
    }
};