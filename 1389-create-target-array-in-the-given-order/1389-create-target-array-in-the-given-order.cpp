class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector <int> res(nums.size());
        int count=0;
        for(int i=0;i<nums.size();i++){

            for(int j=count;j>index[i];j--){
                res[j] = res[j-1];     
            }

            res[index[i]]=nums[i];
            count++;
            
        }
        return res;
        
    }
};