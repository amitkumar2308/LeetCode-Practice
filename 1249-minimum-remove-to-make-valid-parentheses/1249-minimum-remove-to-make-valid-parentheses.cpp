 class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp;

        int open = 0 ;


        for(char c:s){
            if(c=='('){
                open++;
                temp.push_back(c);
            }else if(c==')'){
                if(open>0){
                    open--;
                    temp.push_back(c);
                }
            }else{
                temp.push_back(c);
            }
        }

        string result;
        int close = 0;

        for(int i=temp.size()-1; i>=0; i--){
            if(temp[i]==')'){
                close++;
                result.push_back(temp[i]);
            }else if(temp[i]=='('){

                if(close>0){
                    close--;
                    result.push_back(temp[i]);
                }

            }else{
                result.push_back(temp[i]);
            }
        }

        reverse(result.begin(),result.end());
        return result;

    }
};