class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int min=10000;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min) {
                min=prices[i];
                continue;
            }
            if((prices[i]-min)>maxP){
                maxP=prices[i]-min;
            }
        }
        return maxP;
    }
};