class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> project;

        int n = profits.size();

        for(int i=0; i<n; i++){
            project.push_back({capital[i],profits[i]});
        }

        sort(project.begin(),project.end());
        
        priority_queue<int>maxheap;
        int i = 0;

        while(k--){
            while(i<n && project[i].first <= w){
                maxheap.push(project[i].second);
                i++;
            }

           if(maxheap.empty()) break;

           w += maxheap.top();
           maxheap.pop();
        }

        return w;
    }
};