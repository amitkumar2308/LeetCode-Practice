class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>frq;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>mH;
        vector<int>result;

        for(int num:nums){
            frq[num]++;
        }

        for(auto &it:frq){
            mH.push({it.second,it.first});
            if(mH.size()>k){
                mH.pop();
            }
        }

        while(!mH.empty()){
            result.push_back(mH.top().second);
            mH.pop();
        }

        return result;
    }
};