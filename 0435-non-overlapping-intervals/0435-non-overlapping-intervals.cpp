class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
         vector<pair<int,int>>mp;

        for(auto interval:intervals){
            mp.push_back({interval[1],interval[0]});
        }

        sort(mp.begin(),mp.end());
        
        int count =0;
        int finish =INT_MIN;
        for(auto p:mp){
            if(p.second>=finish){
                count++;
                finish = p.first;
            }
        }

        return mp.size()-count;
       
    }
};