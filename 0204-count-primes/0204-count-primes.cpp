class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;

        vector<bool>isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=4;i<n;i+=2){
            isPrime[i]=false;
        }

        for(long long i=3;i*i<n;i++){
            if(isPrime[i]){
                for(long long j=i*i;j<n;j+=2*i){
                    isPrime[j]=false;
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++) {
            if(isPrime[i]){
                count++;
            }
        }

        return count;
    }
};