class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int low=0;
        int high=x;
        while(low<=high){
            long long mid = low +(high-low)/2;

            if(mid*mid==x) return mid;

            if(mid * mid> x) {
                
                high = mid-1;
            }

            else {
                ans=mid;
                low = mid+1;
            }
        }     
        return ans;   
    }
};