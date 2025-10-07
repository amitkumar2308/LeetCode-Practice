class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(dict.find(endWord)== dict.end()) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto[word,level] = q.front();
            q.pop();

            if(word == endWord) return level;

            for(int i=0; i<word.size(); i++){
                string temp = word;
                for(char c = 'a'; c<='z'; c++){
                    temp[i] = c;

                    if(dict.find(temp)!= dict.end()){
                        q.push({temp,level+1});
                        dict.erase(temp);
                    }
                }
            }

        }
    return 0; 
    }
};