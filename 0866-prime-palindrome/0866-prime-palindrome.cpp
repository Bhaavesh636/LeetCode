class Solution {
public:
    bool isPrime(int n){
        if(n<2)    return false;
        if(n==2)   return true;
        if(n%2==0) return false;
        
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }

    int makePal(int n){
        int pal=n;
        n/=10;

        while(n>0){
            pal= pal * 10 + n % 10;
            n/=10;
        }

        return pal;

    }

    int primePalindrome(int n) {
       if(n<=2) return 2;
       if(n==3) return 3;
       if(n<=5) return 5;
       if(n<=7) return 7;
       if(n<=11)return 11;

       for(int i=10; ;i++){
        int pal=makePal(i);
        if(pal>=n && isPrime(pal)){
            return pal;
        }
       }
    }
};