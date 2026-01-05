class Solution {
public:
    bool DFS(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>& recStack,stack<int>&st){
            visited[node] = true;
            recStack[node] = true;
            
            for(auto nbr:adj[node]){
                if(!visited[nbr]){
                   if(DFS(nbr,adj,visited,recStack,st))
                    return true;
                }else if(recStack[nbr]){
                    return true;
                }
            }
            recStack[node] = false;
            st.push(node);
            return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          int V = numCourses;
          unordered_map<int,vector<int>>adj;
          vector<bool>visited(V,false);
            vector<bool> recStack(V, false);
          stack<int>st;
          for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
          };
          
          for(int i=0; i<V; i++){
              if(!visited[i]){
                if(DFS(i,adj,visited,recStack,st)){
                return {};
                }
              }
          };


          vector<int>result;
          while(!st.empty()){
            int front =  st.top();
            result.push_back(front);
            st.pop();
          }
    return result;
        
    }
};