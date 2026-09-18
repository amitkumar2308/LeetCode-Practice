class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> L(26, -1);
        vector<int> R(26, -1);
        
        // 1. Record the first (L) and last (R) occurrences of each character
        for (int i = 0; i < n; ++i) {
            if (L[s[i] - 'a'] == -1) {
                L[s[i] - 'a'] = i;
            }
            R[s[i] - 'a'] = i;
        }
        
        // Store valid intervals as pairs of {left, right}
        vector<pair<int, int>> intervals;
        
        // 2. Find valid substrings starting from the first occurrence of each character
        for (int c = 0; c < 26; ++c) {
            if (L[c] == -1) continue;
            
            int left = L[c];
            int right = R[c];
            bool isValid = true;
            
            for (int i = left; i <= right; ++i) {
                // If a character forces us to expand leftward, this starting point is invalid
                if (L[s[i] - 'a'] < left) {
                    isValid = false;
                    break;
                }
                // Expand the right boundary to include all occurrences of the current character
                right = max(right, R[s[i] - 'a']);
            }
            
            if (isValid) {
                intervals.push_back({left, right});
            }
        }
        
        // 3. Sort primarily by right bound (ascending), secondarily by left bound (descending)
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        
        // 4. Greedily pick non-overlapping substrings
        vector<string> ans;
        int last_end = -1;
        
        for (const auto& interval : intervals) {
            if (interval.first > last_end) {
                ans.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                last_end = interval.second;
            }
        }
        
        return ans;
    }
};