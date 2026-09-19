class Solution {
public:
    double myPow(double x, int n) {
        double pow=1;
        while(n>1){
            if(n%2==1){
                pow*=x;
            }
            x*=x;
            n/=2;
        }
        while(n<-1){
            if(n%2!=0){
                pow/=x;
            }
            n/=2;
            x*=x;
        }
        if(n>0)
            pow*=x;
        else if(n<0)
            pow/=x;
        
        return pow;
    }
};