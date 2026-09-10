class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1] != 9){
            digits[digits.size()-1]++;

            return digits;
        }

        int i = digits.size()-1;

        if(i==0){
            digits.resize(2);
            digits[0]=1;
            digits[1]=0;

            return digits;
        }

        digits[i]=0;
        digits[--i]++;

        while(digits[i]>9 && i>0){
            digits[i] =0 ;
            digits[--i]++;
        }
        
        if(digits[0]==10){
            digits.resize(digits.size()+1);
            for(int i= digits.size()-2;i > 0 ;i--){
                digits[i]=digits[i+1];
            }

            digits[0]=1;
            digits[1]=0;
        }

        return digits;
    }
};