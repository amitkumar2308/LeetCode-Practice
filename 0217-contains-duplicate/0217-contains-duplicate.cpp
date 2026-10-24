class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dup;

        for (int x : nums) {
            dup[x]++;
        }

        for (auto& p : dup) {
            if (p.second > 1) {
                return true;
            }
        }

        return false;
    }
};