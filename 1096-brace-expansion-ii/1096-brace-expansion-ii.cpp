class Solution {
public:

    string s;
    int i = 0;

    set<string> parseExpression() {

        set<string> result;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                i++;
                continue;
            }

            set<string> part = parseTerm();

            result.insert(part.begin(), part.end());
        }

        return result;
    }

    set<string> parseTerm() {

        set<string> result = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> part;

            if (s[i] == '{') {

                i++; // {

                part = parseExpression();

                i++; // }

            }
            else {

                part.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : result) {
                for (string b : part) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};