class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int sol=0;
        for(auto [num,freq] : mp){
            if(mp.find(num+1)!=mp.end()){
                int sum= freq + mp[num+1];
                if(sum>sol)  sol=sum;
            }
        }

        return sol;
        
    }
};