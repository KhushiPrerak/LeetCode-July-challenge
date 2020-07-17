class Solution {
public:
    double myPow(double x, int n) {
        
        bool isNeg = false;
        if(n<0) isNeg = true;
        
        n= abs(n);
        if(n==0) return 1;
        if(x==0 || x==1) return x;
        
        double ans = myPow(x,n/2);
        if(n%2!=0) ans = ans*ans*x;
        else ans = ans*ans;
        return isNeg ? 1/ans : ans;
        
    }
};
