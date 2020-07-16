//Pow(x, n)

class Solution {
public:
    double myPow(double x, int n)
    {
        long long N=n;
        if(N<0)
        {
            N=-N;
            x=1/x;
        }
        return fastPow(x,N);
    }
    double fastPow(double x,long long n)
    {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n%2==0)
        {
            double y=fastPow(x,n/2);  
            return y*y;   // y*y->optimization : lesser number of calls than fastPow(x,n/2)* fastPow(x,n/2)
        }
        return x*fastPow(x,n-1);
    }
};
