class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 1 || k < 1)
            return 0;

        unordered_map<int, int> mp;

        for (int i = 1; i <= n+1; i++) {
            mp[i] = k * i;
        }

        int result = INT_MAX;
        for (auto& p : mp) {
            bool found = false;
            for (int x : nums) {

                if (x == p.second) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result = min(result, p.second);
            }
        }

        return result;
    }
};