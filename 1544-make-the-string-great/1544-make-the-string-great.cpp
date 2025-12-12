class Solution {
public:
    string makeGood(string s) {
      string result = "";

      for(char c:s){
        if(!result.empty() && abs(result.back()-c)==32){   //ASCII VALUE USE KISI BHI SMALL CASE KA USKE SIMILAR CAPITAL LETTER SE DIFFERENCE 32 HOGA
            result.pop_back();
        }else{
            result.push_back(c);
        }
      }
      return result;
    }
};