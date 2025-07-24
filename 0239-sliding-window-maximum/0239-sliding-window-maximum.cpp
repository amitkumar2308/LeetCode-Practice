class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;

        for(int i=0; i<nums.size(); i++){
            // Step 1: Remove elements out of current window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            
            // Step 2: Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            // Step 3: Add current element index
            dq.push_back(i);


            // Step 4: Store result when window is fully formed
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
    return result;
    }
};