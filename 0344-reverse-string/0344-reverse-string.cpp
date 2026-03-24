class Solution {
public:
    
    void solve(vector<char>& s, int left, int right){
        if(left>=right) return; //base case

        swap(s[left],s[right]);

        solve(s,left+1,right-1);




    }
    
    void reverseString(vector<char>& s) {
        //  //two pointer

        //  int left = 0;
        //  int right = s.size()-1;

        // while(left<right){
        //     swap(s[left],s[right]);
        //     left++;
        //     right--;
        // }

        //recursion 

        solve(s,0,s.size()-1);


    
    }
};