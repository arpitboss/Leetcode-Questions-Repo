class Solution {
public:
    int addDigits(int num) {
        if (num==0) {
            return 0;
        }
        
        int sum = addDigits(num/10)+num%10;
        if ((sum/10)>0) {
            return addDigits(sum);
        }
        return sum;
    }
};