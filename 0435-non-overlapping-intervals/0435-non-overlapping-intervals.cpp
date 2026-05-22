class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        ans.push_back(intervals[0]);

        int removecnt = 0;

        for(int i=1; i<n; i++){

            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            int prevEnd = ans.back()[1];

            if(currStart<prevEnd){
                removecnt++;
                ans.back()[1] = min(prevEnd,currEnd);
            }else{
                ans.push_back(intervals[i]);
            }



        }
        return removecnt;
    }
};