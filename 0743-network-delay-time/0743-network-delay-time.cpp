class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);

        unordered_map<int,vector<pair<int,int>>>adj; //src -> (target,time);

        for(vector<int> &vec : times){
            int src = vec[0];
            int target = vec[1];
            int time = vec[2];

            adj[src].push_back({target,time});
        }

        queue<int>q;
        dist[k] = 0;
        q.push(k);

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(auto &p:adj[u]){
                int v = p.first;
                int wt = p.second;

                if(dist[v]>dist[u]+wt){
                    dist[v] = dist[u]+wt;
                    q.push(v);
                }
            }
            
        }

        int maxTime = 0;

        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX) return -1;
            maxTime = max(maxTime,dist[i]);
        }
        
    return maxTime;
    }
};