class Solution {
public:
vector<vector<int>> ans ;
    void solve(int indx,vector<int>nums){
        if(indx==nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=indx;i<nums.size();i++){
            swap(nums[indx],nums[i]);
            solve(indx+1,nums);
            swap(nums[indx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums);
        return ans;
    }
};