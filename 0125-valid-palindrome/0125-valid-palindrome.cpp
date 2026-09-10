class Solution {
public:
    bool isPalindrome(string s) {
        string nor="";
        for(char ch : s){
            if(isalnum(ch)){
                nor+=tolower(ch);
            }
        }

        int i=0,j=nor.length()-1;
        while(i<=j){
            if(nor[i++]!=nor[j--]){
                return false;
            }
        }

        return true;
        
    }
};