class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int distinctPrimeFactors(vector<int>& nums) {

        unordered_set<int> s;
        for(int n:nums){
            for(int i=2;i<=n;i++){
                if(isPrime(i)&&n%i==0){
                    s.insert(i);
                }
            }
        }
        return s.size();
        

        



    }
};