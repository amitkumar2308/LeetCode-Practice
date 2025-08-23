class Solution {
public:
    int jump(vector<int>& nums) {
        int n =  nums.size();

        if(n==1) return 0;

        int jumps = 0, currentEnd = 0, furthest = 0;
        for(int i=0; i<n-1; i++){
            furthest = max(furthest, i+nums[i]);
            if(furthest<=i) return -1;
            if(i== currentEnd){
                jumps++;
                currentEnd = furthest;
                if(currentEnd>= n-1) return jumps;
            }
        }
    return -1;
    }
};