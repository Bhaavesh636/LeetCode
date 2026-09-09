class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(char ch1: s){
            mp1[ch1]++;
        }

        for(char ch2: t){
            mp2[ch2]++;
        }

        if(mp1 == mp2) return true;

        return false;
    }
};