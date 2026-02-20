class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          if(intervals.empty()) return {};
          int n = intervals.size();
          sort(intervals.begin(),intervals.end());

          vector<vector<int>>minterval;
          minterval.push_back(intervals[0]);

          for(int i=1; i<n; i++){

            vector<int>&curr = intervals[i];
            vector<int>&last = minterval.back();

            if(last[1]>=curr[0]){
               last[1] = max(last[1],curr[1]);
            }else{
                minterval.push_back(curr);
            }

          }

    return minterval;
    }
};