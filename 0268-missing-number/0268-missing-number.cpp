class Solution {
public:
    int missingNumber(vector<int>& nums) {              //TC = nlogn
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]!= res)
                break;
            res++;
        }
        return res;
        
    }
};