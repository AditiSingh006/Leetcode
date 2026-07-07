class Solution {
public:
    long long sumAndMultiply(int n) {
        long long a;
        long long s = 0;
        int sum = 0;

        while(n){
            int digit = n % 10;

            if (digit != 0)
                s = s * 10 + digit;

            sum += digit;
            n /= 10;
        }

        while(s){
            a = (a*10) + (s%10);
            s = s / 10;
        }

        return a * sum;

    }
};