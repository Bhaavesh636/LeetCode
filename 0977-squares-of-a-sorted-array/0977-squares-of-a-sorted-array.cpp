class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int i=0,j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                res[k--]=nums[i]*nums[i];
                i++;
            }

            else{
                res[k--]=nums[j]*nums[j];
                j--;
            }

        }

        return res;
    }
};