class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();
       int curr = 0;
       int write = 0;

       while(curr<n){
        int last = curr;

        while(last<n && chars[last]==chars[curr]){
            last++;
        }
        chars[write++] = chars[curr];

        int count = last-curr;
        if(count>1){
            for(char c:to_string(count)){
                chars[write++] = c;
            }
        }
           curr = last;
       }
       return write;
    }
};