class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0;
        int R = nums.size()-1;
        while(L<=R){
            if(nums[L] % 2 == 0){
                L++;
            }

            else if(nums[R] % 2 == 1){
                R--;
            }

            else{
                swap(nums[L],nums[R]);
            }
        }
        return nums;
        
    }
};