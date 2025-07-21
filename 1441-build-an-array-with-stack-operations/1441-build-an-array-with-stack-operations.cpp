class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
           
           int i =0;
           int stream = 1;
           vector<string>result;
           while(i<target.size() && stream<=n){
                 result.push_back("Push");

                 if(target[i]==stream){
                    i++;
                 }else{
                    result.push_back("Pop");
                 }
                 stream++;
           }
    return result;
    }
};