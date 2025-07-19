class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
           vector<int>st;

           for(int x:asteroids){
            bool destroyed = false;

            while(!st.empty() && x<0 && st.back()>0){
                 if(abs(x)>abs(st.back())){
                    st.pop_back();
                    continue;
                 }else if(abs(x)==abs(st.back())){
                    st.pop_back();
                 }
                 destroyed = true;
                 break;
            }

            if(!destroyed){
                st.push_back(x);
            }
           }

         return st;
    }
};