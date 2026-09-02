bool isPalindrome(int x) {
    long int rev=0;
    int temp=x;
    while(temp>0){
        int u=temp%10;
        rev+=u;
        rev*=10;
        temp/=10;
    }
    rev/=10;
    if(rev==x) return true;
    return false;
}