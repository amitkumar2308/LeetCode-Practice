class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.length()<8) return false;
        bool hasLower   = false;
        bool hasUpper   = false;
        bool hasDigit   = false;
        bool hasSpecial   = false;

        string specialChars = "!@#$%^&*()_+-";

        for(int i=0; i<password.length(); i++){
               char ch = password[i];

               if(i>0 && ch==password[i-1]){
                return false;
               }


               if(islower(ch)) hasLower = true;
               if(isupper(ch)) hasUpper = true;
               if(isdigit(ch)) hasDigit = true;
               else{
                 if(specialChars.find(ch)!= string::npos){
                    hasSpecial = true;
                 }
               }
        } 
    return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};