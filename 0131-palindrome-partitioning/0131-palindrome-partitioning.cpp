class Solution {
public:
    bool palindrome(string &s, int i, int j){

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void backtrack(string &s, int start, vector<string>&current, vector<vector<string>>& result){
        if(start == s.size()){
            result.push_back(current);
            return;
        }
        for(int end = start; end<s.size(); end++){
            if(palindrome(s,start,end)){
                current.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1,current,result);
                current.pop_back();
                
            }
        }

    }
    vector<vector<string>> partition(string s) {
           vector<vector<string>> result;
           vector<string> current;
           backtrack(s,0,current,result);
           return result;
    }
};