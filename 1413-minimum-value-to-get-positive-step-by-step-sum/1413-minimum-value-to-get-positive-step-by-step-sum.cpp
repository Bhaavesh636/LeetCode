class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int i=1;
        while(i>=1){
            bool check=true;
            int sum=i;
            for(int j=0;j<nums.size();j++){
                sum+=nums[j];
                if(sum<1){
                    check=false;
                }                
            }

            if(check) return i;

            i++;
        }

        return -1;
        
    }
};