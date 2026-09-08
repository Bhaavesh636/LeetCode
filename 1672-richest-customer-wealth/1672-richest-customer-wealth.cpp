class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0;
        for(vector<int>acc : accounts){
            int sum=0;
            for(int i=0;i<acc.size();i++){
                sum+=acc[i];
            }
            if(max<sum) max=sum;
        }

        return max;
    }
};