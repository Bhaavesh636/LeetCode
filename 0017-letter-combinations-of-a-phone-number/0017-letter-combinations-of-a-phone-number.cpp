class Solution {
public:
    vector<string> ans;

    unordered_map<int,string> mp;

    void solve(string digits,int indx,string curr){

        if(indx==digits.size()){
            ans.push_back(curr);
            return;
        }
        string temp= mp[digits[indx]-'0'];

        for(char ch: temp){
            curr.push_back(ch);
            solve(digits,indx+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        mp[2]="abc" ; mp[3]="def"; mp[4]="ghi"; mp[5]="jkl"; mp[6]="mno"; mp[7]="pqrs"; mp[8]="tuv"; mp[9]="wxyz";
        solve(digits,0,"");
        return ans;
    }
};