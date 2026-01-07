class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
         vector<int>color(n,0); 

         for(int i=0; i<n; i++){
            if(color[i]!=0) continue;

            queue<int>q;
            q.push(i);
            color[i]=1;

            while(!q.empty()){
                int node = q.front(); q.pop();

                for(int nbr :graph[node]){
                    if(color[nbr]==0){
                        color[nbr] = -color[node];
                        q.push(nbr);
                    }else if(color[nbr]==color[node]){
                        return false;
                    }
                }
            }
         }
    return true;
    }
};