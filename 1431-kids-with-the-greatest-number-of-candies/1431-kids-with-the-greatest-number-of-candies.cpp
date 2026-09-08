class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>res(candies.size());
        int ind=0;

        for(int i=0;i<candies.size();i++){
            bool m =true;
            for(int j=0;j<candies.size();j++){
                if (candies[i] + extraCandies < candies[j]){
                    m =false;
                }
            }
            res[ind++]=m;
        }

        return res;
    }
};