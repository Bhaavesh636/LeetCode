class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n = nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double avg = (double)sum/k;
        double max=avg;

        for(int i=k;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-k];

            avg = (double)sum/k;
            if(avg>max) max=avg;
        }

        return max;

    }
};