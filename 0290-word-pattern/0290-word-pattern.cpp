class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;

        stringstream ss(s);
        vector<string>words;
        string word;

        while(ss>>word)
            words.push_back(word);
        
        if(words.size()!=pattern.length()) return false;
        
        for(int i=0;i<words.size();i++){
            if(mp1.find(pattern[i])==mp1.end()){
                mp1[pattern[i]]=words[i];
            }

            else if(mp1[pattern[i]]!= words[i]){
                return false;
            }

            if(mp2.find(words[i])==mp2.end()){
                mp2[words[i]]=pattern[i];
            }

            else if(mp2[words[i]]!=pattern[i]){
                return false;
            }
        }
        return true;
    }
};