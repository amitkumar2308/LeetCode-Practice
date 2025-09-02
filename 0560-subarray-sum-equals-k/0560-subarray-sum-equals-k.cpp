class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        int currsum = 0; int count=0;
        mp[0] =1;
        for(int num:nums){
            currsum+=num;

            if(mp.find(currsum-k)!=mp.end()){
                count += mp[currsum-k];
            }

        mp[currsum]++;
        }

    return count;
    }
};