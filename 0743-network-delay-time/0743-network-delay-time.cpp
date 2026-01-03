class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1); //(neighbor,weight)
        for(auto &t:times){
            int u = t[0],v=t[1],w=t[2];
            graph[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()){
            auto[time,node] = pq.top();pq.pop();
            if(time>dist[node]) continue;

            for(auto &[nei,w]:graph[node]){
                if(time+w<dist[nei]){
                    dist[nei] = time + w;
                    pq.push({dist[nei],nei});
                }
            }
        }
      int ans = 0;
      for(int i=1; i<=n; i++){
        if(dist[i]==INT_MAX) return -1;
        ans = max(ans,dist[i]);
      }

    return ans;
    }
};