class Solution {
public:
    bool isPalindrome(string s) {
          
          string v = "";

          for(char c:s){
            if(isalnum(c)){
             v.push_back(tolower(c));
            }
          };

          int left = 0;
          int right = v.size()-1;
          while(left<right){
              if(v[left]!=v[right]){
                return false;
              }
              left++;
              right--;
          }
        return true;
    }
};