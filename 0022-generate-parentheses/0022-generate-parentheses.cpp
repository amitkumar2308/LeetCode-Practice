class Solution {
public:
    vector<string> ans;

    void solve(int n, int open, int close, string curr) {

        // Complete valid combination
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Choice 1: add '('
        if (open < n) {
            solve(n, open + 1, close, curr + '(');
        }

        // Choice 2: add ')'
        if (close < open) {
            solve(n, open, close + 1, curr + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
};