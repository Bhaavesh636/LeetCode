class Solution {
public:
   vector<vector<int>>ans;
    void solve(int index,vector<int>&nums ,vector<int> temp,int sum,int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(index == nums.size() || sum>target)  return;

        temp.push_back(nums[index]);
        solve(index,nums,temp,sum+nums[index], target);
        temp.pop_back();
        solve(index+1,nums,temp,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0,candidates,{},0,target);
        return ans;
    }
};