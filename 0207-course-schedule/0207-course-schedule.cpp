class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        
        //Graph 
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            
            adj[prerequisite].push_back(course);  
        }

        // Find all in-degree
        vector<int> indegree(numCourses, 0);
        for (auto i : adj) {
            for (auto j : i.second) {
                indegree[j]++;
            }
        }

        queue<int> q;  

        // Push nodes with 0 in-degree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        
        // BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            // Reduce in-degree for neighbors
            for (auto neighbor : adj[front]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == numCourses;  
    }
};
