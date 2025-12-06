class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
       set<int>st;

       for(int val : nums){
        st.insert(val);
       };

       int currFreq = 0;
       int maxFreq = 0;
       int prev = INT_MIN;

       for(int value:st){
        if(value==prev+1){
            currFreq++;
        }else{
            currFreq = 1;
        }
        maxFreq = max(currFreq,maxFreq);
        prev = value;
       }
    return maxFreq;
    }
};