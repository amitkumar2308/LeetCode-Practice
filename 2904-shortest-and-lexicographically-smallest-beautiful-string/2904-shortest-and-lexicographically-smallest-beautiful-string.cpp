class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        string ans = "";
        int count = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                count++;
            }

            while (count > k) {
                if (s[left] == '1') {
                    count--;
                }
                left++;
            }

            if (count == k) {
                while (s[left] == '0') {
                    left++;
                }
                string curr = s.substr(left, right - left + 1);

                if (ans == "") {
                    ans = curr;
                } else if (curr.length() < ans.length()) {
                    ans = curr;
                } else if (curr.length() == ans.length() && curr < ans) {
                    ans = curr;
                }
            }
        };
        return ans;
    }
};