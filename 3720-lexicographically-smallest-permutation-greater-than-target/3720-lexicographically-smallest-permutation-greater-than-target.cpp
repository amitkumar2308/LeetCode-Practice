#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Find the maximum prefix of target that s can match
        int max_prefix_len = 0;
        vector<int> temp = cnt;
        for (int i = 0; i < n; i++) {
            int char_idx = target[i] - 'a';
            if (temp[char_idx] == 0) break;
            temp[char_idx]--;
            max_prefix_len++;
        }

        // Try placing a character greater than target[i] at position i
        // Iterate backwards from max_prefix_len down to 0 to maximize prefix match
        for (int i = max_prefix_len; i >= 0; i--) {
            if (i == n) continue; // Divergence cannot happen at index n

            // Remaining available characters after taking target[0 ... i-1]
            vector<int> rem = cnt;
            for (int j = 0; j < i; j++) {
                rem[target[j] - 'a']--;
            }

            // Pick the smallest character strictly greater than target[i]
            int target_char = target[i] - 'a';
            for (int c = target_char + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += (char)('a' + c);
                    rem[c]--;

                    // Fill remaining characters in ascending order
                    for (int ch = 0; ch < 26; ch++) {
                        ans.append(rem[ch], 'a' + ch);
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};