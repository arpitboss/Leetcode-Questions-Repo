class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }
        
        bool sign = true;
        if ((dividend<=0 && divisor>0)) {
            sign = false;
        }
        else if ((dividend>=0 && divisor<0)) {
            sign = false;
        }
        long n = abs(dividend);
        long d = abs(divisor);
        long ans = 0;
        while (n>=d) {
            int c = 0;
            while (n >= (d<<(c+1))) {
                c++;
            }
            n = n - (d<<c);
            ans += (1<<c);
        }
        if (ans == (1<<31) && sign) {
            return INT_MAX;
        }
        if (ans == (1<<31) && !sign) {
            return INT_MIN;
        }
        return sign ? ans : -ans;
    }
};