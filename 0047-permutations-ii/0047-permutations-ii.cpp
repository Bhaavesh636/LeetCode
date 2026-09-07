class Solution {
public:
 vector<vector<int>> ans;
    void solve(vector<int> nums ,int indx){
        if(indx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=indx;i<nums.size();i++){
            swap(nums[indx],nums[i]);
            solve(nums,indx+1);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        set<vector<int>> s(ans.begin(),ans.end());
        vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};