class Solution {
public:
    bool isPalindrome(string s) {
          string characters = "";

          for(char c:s){
            if(isalnum(c)){
                characters.push_back(tolower(c));
            }
          }

          int left = 0, right = characters.size()-1;

          while(right>left){
            if(characters[left]!=characters[right]){
                return false;
            }
            left++;
            right--;
          }

    return true;
    }
};